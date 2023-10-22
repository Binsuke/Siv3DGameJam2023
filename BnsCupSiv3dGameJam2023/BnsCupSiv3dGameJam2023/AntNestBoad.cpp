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
		
		InitFlg = true;
	}
}

bool AntNestBoad::OnClicked(int x, int y) {

	if (NestRect[x][y].leftClicked()) {
		NestData[x][y] = eNestData::Open;
		iColor[x][y] = iColorPicker[eNestData::cpOpen];
		fColor[x][y] = fColorPicker[eNestData::cpOpen];
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

void AntNestBoad::BoadOpen(int32 x, int32 y) {
	if (isValid(x,y) ){
		NestData[x][y] = eNestData::Open;
		BoadUpdate(x, y);
	}
}
