#include "stdafx.h"
#include "AntNestBoad.h"


void AntNestBoad::Draw()
{
	if (!InitFlg) {
		Print << U"RECTデータの初期化がされていません";
		return;
	}
	

	for (int x = 0; x < NestSize::_W; x++) {
		for (int y = 0; y < NestSize::_H; y++) {
			NestRect[x][y].draw(iColor[x][y]);
			NestRect[x][y].drawFrame(5, 5, fColor[x][y]);
		};		
	}

	BonusInfoDraw();
}


void AntNestBoad::Init() {
	if (!InitFlg) {
		int32 PosX, PosY, SizeW, SizeH;

		//各カラー設定 iColorPickerがインナーカラー
		//             fColorPiuckerがフレイムカラー
		iColorPicker[eNestData::cpClose] = ColorF(0.1);
		iColorPicker[eNestData::cpOpen] = ColorF(0.7);
		iColorPicker[eNestData::cpMouseOver] = ColorF(0.4);
		iColorPicker[eNestData::cpMouseOverCant] = ColorF(1.0);
		iColorPicker[eNestData::cpBuildMouseOver] = ColorF(0.8);
		iColorPicker[eNestData::cpBuild] = ColorF(0.7, 0.5, 0, 3);

		fColorPicker[eNestData::cpClose] = ColorF(0.2);
		fColorPicker[eNestData::cpOpen] = ColorF(0.6);
		fColorPicker[eNestData::cpMouseOver] = ColorF(0.3);
		fColorPicker[eNestData::cpMouseOverCant] = ColorF(0.9);
		fColorPicker[eNestData::cpBuildMouseOver] = ColorF(0.7);
		fColorPicker[eNestData::cpBuild] = ColorF(0.8, 0.5, 0.3);

		InitCanOpenSet(Param::InitPosx, Param::InitPosY);//仮の最初の穴

		BoadOpen(Param::InitPosx, Param::InitPosY);

		for (int x = 0; x < NestSize::_W; x++) {
			for (int y = 0; y < NestSize::_H; y++) {
				PosX = AntNestBoad::Param::Pos_TopLeft_X + AntNestBoad::Param::SizeW * x + 10 * x;
				PosY = AntNestBoad::Param::Pos_TopLeft_Y + AntNestBoad::Param::SizeH * y + 10 * y;
				SizeW = AntNestBoad::Param::SizeW;
				SizeH = AntNestBoad::Param::SizeH;

				NestRect[x][y] = Rect{ PosX,PosY,SizeW,SizeH };
				NestRect[x][y] = Rect{ PosX,PosY,SizeW,SizeH };


				switch (NestData[x][y]) {
				case eNestData::Open:
					iColor[x][y] = iColorPicker[eNestData::cpOpen];
					fColor[x][y] = fColorPicker[eNestData::cpOpen];
					break;
				case eNestData::Close:
					iColor[x][y] = iColorPicker[eNestData::cpClose];
					fColor[x][y] = fColorPicker[eNestData::cpClose];
					break;
				case eNestData::canOpen:
					iColor[x][y] = iColorPicker[eNestData::cpCanOpen];
					fColor[x][y] = fColorPicker[eNestData::cpCanOpen];
					break;
				}

			};
		}

		cDrawWindow.InitWindow(AntNestBoad::Param::WindowX, AntNestBoad::Param::WindowY, AntNestBoad::Param::WindowW, AntNestBoad::Param::WindowH,
			AntNestBoad::Param::OKWindowX, AntNestBoad::Param::OKWindowY, AntNestBoad::Param::OKWindowW, AntNestBoad::Param::OKWindowH);

		cDrawWindow.SetColor(ColorF(Palette::Skyblue), ColorF(Palette::Darkblue), ColorF(Palette::White), ColorF(Palette::Whitesmoke));

		//ボーナスの描画用の文字列の設定

		BonusInfoStr[eNestBonusData::ANT] = U"大人アリを見つけました";
		BonusInfoStr[eNestBonusData::FOOD] = U"食料を手に入れました";
		BonusInfoStr[eNestBonusData::UnkANT] = U"隠れていた大人アリを見つけました";
		BonusInfoStr[eNestBonusData::UnkFood] = U"隠れいていた食料を見つけました";
		BonusInfoStr[eNestBonusData::UnkEnemy] = U"隠れていた敵を見つけてしまいました";


		

		InitBoadBonus();
		SetBoadBonus();

		InitFlg = true;
	}
}

bool AntNestBoad::OnClicked(int x, int y) {

	if (NestRect[x][y].leftClicked()) {
		NestData[x][y] = eNestData::Open;
		iColor[x][y] = iColorPicker[eNestData::cpOpen];
		fColor[x][y] = fColorPicker[eNestData::cpOpen];
		SearchFlg = true;
		_SearchtmpX = x;
		_SearchtmpY = y;
		BoadUpdate(x, y);
		return true;
	}
	return false;
}

bool AntNestBoad::BuildOnClicked(int x, int y) {
	if (NestRect[x][y].leftClicked()) {
		NestData[x][y] = eNestData::Build;
		iColor[x][y] = iColorPicker[eNestData::cpBuild];
		fColor[x][y] = fColorPicker[eNestData::cpBuild];
		++HouseCnt;
		BoadUpdate(x, y);
		return true;
	}
	return false;
}

bool AntNestBoad::MouseOveredChangeColor(bool OpenFlg) {

	if (OpenFlg) {
		for (int x = 0; x < NestSize::_W; x++) {
			for (int y = 0; y < NestSize::_H; y++) {
				if (NestRect[x][y].mouseOver() && NestData[x][y] == eNestData::canOpen) {
					iColor[x][y] = iColorPicker[eNestData::cpMouseOver];
					fColor[x][y] = fColorPicker[eNestData::cpMouseOver];
					return OnClicked(x, y);
				}
				else if (iColor[x][y] == iColorPicker[eNestData::cpMouseOver]) {
					switch (NestData[x][y]) {
					case eNestData::Open:
						iColor[x][y] = iColorPicker[eNestData::cpOpen];
						fColor[x][y] = fColorPicker[eNestData::cpOpen];
						break;
					case eNestData::Close:
						iColor[x][y] = iColorPicker[eNestData::cpClose];
						fColor[x][y] = fColorPicker[eNestData::cpClose];
						break;
					case eNestData::canOpen:
						iColor[x][y] = iColorPicker[eNestData::cpCanOpen];
						fColor[x][y] = fColorPicker[eNestData::cpCanOpen];
						break;
					}
				}
			}
		}
	}
	return false;
}


bool AntNestBoad::BuildMouseOveredChangeColor(bool OpenFlg) {
	if (OpenFlg) {
		for (int x = 0; x < NestSize::_W; x++) {
			for (int y = 0; y < NestSize::_H; y++) {
				if (NestRect[x][y].mouseOver() && NestData[x][y] == eNestData::Open){
					iColor[x][y] = iColorPicker[eNestData::cpBuildMouseOver];
					fColor[x][y] = fColorPicker[eNestData::cpBuildMouseOver];
					return BuildOnClicked(x, y);
				}
				else if (iColor[x][y] == iColorPicker[eNestData::cpBuildMouseOver]) {
					switch (NestData[x][y]) {
					case eNestData::Open:
						iColor[x][y] = iColorPicker[eNestData::cpOpen];
						fColor[x][y] = fColorPicker[eNestData::cpOpen];
						break;
					case eNestData::Close:
						iColor[x][y] = iColorPicker[eNestData::cpClose];
						fColor[x][y] = fColorPicker[eNestData::cpClose];
						break;
					case eNestData::canOpen:
						iColor[x][y] = iColorPicker[eNestData::cpCanOpen];
						fColor[x][y] = fColorPicker[eNestData::cpCanOpen];
						break;
					}
				}
			}
		}
	}
	return false;
}

void AntNestBoad::BoadClear() {
	for (int x = 0; x < NestSize::_W; x++) {
		for (int y = 0; y < NestSize::_H; y++) {
				NestData[x][y] = eNestData::Close;
		}
	}
}


void AntNestBoad::BoadUpdate(int32 x,int32 y) {

	int32 tmpx = x;
	int32 tmpy = y;

	//上方向
	tmpy -= 1;
	if (tmpy >= 0) {
		if (NestData[tmpx][tmpy] == eNestData::Close || NestData[tmpx][tmpy] == eNestData::canOpen) {
			NestData[tmpx][tmpy] = eNestData::canOpen;
		}
		//else if (NestData[tmpx][tmpy] == eNestData::Open) {
		//	BoadUpdate(tmpx, tmpy);
		//}
	}

	//右方向
	tmpx = x + 1;
	tmpy = y;
	if (tmpx < Param::SizeW) {
		if (NestData[tmpx][tmpy] == eNestData::Close || NestData[tmpx][tmpy] == eNestData::canOpen){
			NestData[tmpx][tmpy] = eNestData::canOpen;
		}
		//else if (NestData[tmpx][tmpy] == eNestData::Open) {
		//	BoadUpdate(tmpx, tmpy);
		//}
	}

	//左
	tmpx = x - 1;
	tmpy = y;

	if (tmpx >= 0) {
		if (NestData[tmpx][tmpy] == eNestData::Close || NestData[tmpx][tmpy] == eNestData::canOpen) {
			NestData[tmpx][tmpy] = eNestData::canOpen;
		}
		//else if (NestData[tmpx][tmpy] == eNestData::Open) {
		//	BoadUpdate(tmpx, tmpy);
		//}
	}

	//下

	tmpx = x;
	tmpy = y + 1;

	if (tmpy < Param::SizeH) {
		if (NestData[tmpx][tmpy] == eNestData::Close || NestData[tmpx][tmpy] == eNestData::canOpen) {
			NestData[tmpx][tmpy] = eNestData::canOpen;
		}
		//else if (NestData[tmpx][tmpy] == eNestData::Open) {
		//	BoadUpdate(tmpx, tmpy);
		//}
	}



}

void AntNestBoad::InitCanOpenSet(int x, int y) {
	if (x >= 0 && x < Param::SizeW && y == 0 ) {
		NestData[x][y] = eNestData::canOpen;
	}
	else {
		Print << U"ネストの初期化位置が異常です";
	}
}

bool AntNestBoad::isValid(int32 x, int32 y) {
	if (NestData[x][y] == eNestData::canOpen) {
		return true;
	}
	return false;
}

//void AntNestBoad::BoadOpen(int32 x, int32 y) {
//	if (isValid(x,y) ){
//		NestData[x][y] = eNestData::Open;
//		BoadUpdate(x, y);
//	}
//}

void AntNestBoad::InitBoadBonus() {
	int32 Size = NestSize::_W * NestSize::_H - 1;//初期位置は省く

	float Pertmp[AntNestBoad::eNestBonusData::BONUS_TYPE];

	Pertmp[eNestBonusData::NONE] = (float)Size * (0.01 * (float)eNestBonusData::PAR_NONE);
	Pertmp[eNestBonusData::ANT] = (float)Size * (0.01 * (float)eNestBonusData::PAR_ANT);
	Pertmp[eNestBonusData::FOOD] = (float)Size * (0.01 * (float)eNestBonusData::PAR_FOOD);

	Pertmp[eNestBonusData::UnkANT] = (float)Size * (0.01 * (float)eNestBonusData::PAR_UNK_ANT);

	Pertmp[eNestBonusData::UnkFood] = (float)Size * (0.01 * (float)eNestBonusData::PAR_UNK_FOOD);

	Pertmp[eNestBonusData::UnkEnemy] = (float)Size * (0.01 * (float)eNestBonusData::PAR_UNK_ENEMY);


	for (int i = 0; i < eNestBonusData::BONUS_TYPE; i++) {
		if (Pertmp[i] <= 0) {//パネルが０なら補正
			Pertmp[i] = 1;
		}
	}

	int tmp = 0;
	for (int i = 0; i < Pertmp[eNestBonusData::UnkEnemy]; i++) {//見えない敵から追加
		NestBonusParPanel << eNestBonusData::UnkEnemy;
		++tmp;
	}
	
	for (int i = 0; i < Pertmp[eNestBonusData::UnkFood]; i++) {
		NestBonusParPanel << eNestBonusData::UnkFood;
		++tmp;
	}
	for (int i = 0; i < Pertmp[eNestBonusData::UnkANT]; i++) {
		NestBonusParPanel << eNestBonusData::UnkANT;
		++tmp;
	}
	for (int i = 0; i < Pertmp[eNestBonusData::FOOD]; i++) {
		NestBonusParPanel << eNestBonusData::FOOD;
		++tmp;
	}
	for (int i = 0; i < Pertmp[eNestBonusData::ANT]; i++) {
		NestBonusParPanel << eNestBonusData::ANT;
		++tmp;
	}
	for (int i = 0; i < Pertmp[eNestBonusData::NONE]; i++) {
		NestBonusParPanel << eNestBonusData::NONE;
		++tmp;
	}

	if (Size < tmp) {//全体のサイズとボーナスデータを用意したデータを比較してサイズより多いデータが入っていた場合
		tmp = tmp - Size;//サイズを引いてどれだけ大きいかをだす
		NestBonusParPanel.pop_back_N(tmp);//余分な後ろのデータを削除する
	}
	NestBonusParPanel.shuffle();
}

void AntNestBoad::SetBoadBonus() {
	int tmp = 0;
	for (int x = 0; x < NestSize::_W; x++) {
		for (int y = 0; y < NestSize::_H; y++) {
			if (NestData[x][y] != eNestData::Open) {
				if (tmp < NestBonusParPanel.size()) {
					NestBonusData[x][y] = NestBonusParPanel[tmp];
				}
				else {
					NestBonusData[x][y] = eNestBonusData::NONE;
				}
			}
			++tmp;
		}
	}
}

int32 AntNestBoad::SearchBonus(int32 x, int32 y) {
	if (SearchFlg) {
		if (x < NestSize::_W && y < NestSize::_H) {//範囲外をアクセスしていないか
			if (NestBonusData[x][y] != eNestBonusData::NONE) {
				BonusInfotmpX = x;
				BonusInfotmpY = y;
				BonusDrawFlg = true;
			}
			SearchFlg = false;
			return NestBonusData[x][y];
		}
		SearchFlg = false;
	}
	return eNestBonusData::NONE;//異常がありそうならとりあえずNONEを返しておく
}


int32 AntNestBoad::SearchBonus() {
	
	if (SearchFlg) {
		DebugPrint(_SearchtmpX, U"SearchX");
		DebugPrint(_SearchtmpY, U"SearchY");

		if (_SearchtmpX < NestSize::_W && _SearchtmpY < NestSize::_H) {//範囲外をアクセスしていないか
			if (NestBonusData[_SearchtmpX][_SearchtmpY] != eNestBonusData::NONE) {
				BonusInfotmpX = _SearchtmpX;
				BonusInfotmpY = _SearchtmpY;
				BonusDrawFlg = true;
			}
			SearchFlg = false;
			int32 returntmp = NestBonusData[_SearchtmpX][_SearchtmpY];
			//NestBonusData[_SearchtmpX][_SearchtmpY] = eNestBonusData::NONE;
			return returntmp;
		}
		SearchFlg = false;
	}
	return eNestBonusData::NONE;//異常がありそうならとりあえずNONEを返しておく
}


void AntNestBoad::BonusInfoDraw() {
	

	

	int32 PosX, PosY;

	if (!BonusInfoDrawInitFlg) {
		for (int x = 0; x < NestSize::_W; x++) {
			for (int y = 0; y < NestSize::_H; y++) {
				PosX = AntNestBoad::Param::Pos_TopLeft_X + (AntNestBoad::Param::SizeW+10) * x +AntNestBoad::SizeW / 2 ;
				PosY = AntNestBoad::Param::Pos_TopLeft_Y + (AntNestBoad::Param::SizeH+10) * y +AntNestBoad::SizeH / 2 ;

				switch (NestBonusData[x][y]) {
				case eNestBonusData::FOOD:
					BonusInfoDrawPosX.push_back(PosX);
					BonusInfoDrawPosY.push_back(PosY);
					foodtex.scaled(0.5).drawAt(PosX, PosY);
					break;
				case eNestBonusData::ANT:
					BonusInfoDrawPosX.push_back(PosX);
					BonusInfoDrawPosY.push_back(PosY);
					AntTex.scaled(0.5).drawAt(PosX, PosY);
					break;
				}
			}
		}
	}
	else {
		for (int x = 0; x < BonusInfoDrawPosX.size(); x++) {
			for (int y = 0; y < BonusInfoDrawPosY.size(); y++) {				
				switch (NestBonusData[BonusInfoDrawPosX[x]][ BonusInfoDrawPosY[y]]) {
				case eNestBonusData::FOOD:
					PosX = AntNestBoad::Param::Pos_TopLeft_X + AntNestBoad::Param::SizeW * BonusInfoDrawPosX[x];
					PosY = AntNestBoad::Param::Pos_TopLeft_Y + AntNestBoad::Param::SizeH * BonusInfoDrawPosY[y];

					foodtex.scaled(0.5).drawAt(PosX, PosY);
					break;
				case eNestBonusData::ANT:
					PosX = AntNestBoad::Param::Pos_TopLeft_X + AntNestBoad::Param::SizeW * BonusInfoDrawPosX[x];
					PosY = AntNestBoad::Param::Pos_TopLeft_Y + AntNestBoad::Param::SizeH * BonusInfoDrawPosY[y];

					AntTex.scaled(0.5).drawAt(PosX, PosY);
					break;

				}
			}
		}
	}

	if (BonusInfotmpX >= 0 && BonusInfotmpY >= 0 && BonusDrawFlg) {
		cDrawWindow.Draw(BonusInfoStr[NestBonusData[BonusInfotmpX][BonusInfotmpY]]);
		//cDrawWindow.Draw(U"test");
	}

	if (cDrawWindow.OnClicked()) {
		//MouseL.clearInput();//これを入れるとなぜかバグる

		NestBonusData[_SearchtmpX][_SearchtmpY] = eNestBonusData::NONE;
		BonusDrawFlg = false;
	}
	//cDrawWindow.Draw()
}
