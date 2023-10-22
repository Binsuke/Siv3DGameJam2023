#include "stdafx.h"
#include "AntNestBoad.h"


void AntNestBoad::Draw()
{
	if (!InitFlg) {
		Print << U"RECTデータの初期化がされていません";
		return;
	}
	

	int32 PosX, PosY, SizeW, SizeH;
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
		iColorPicker[NestData::cpClose] = ColorF(0.1);
		iColorPicker[NestData::cpOpen] = ColorF(0.7);
		iColorPicker[NestData::cpMouseOver] = ColorF(0.4);

		fColorPicker[NestData::cpClose] = ColorF(0.2);
		fColorPicker[NestData::cpOpen] = ColorF(0.6);
		fColorPicker[NestData::cpMouseOver] = ColorF(0.3);

		for (int x = 0; x < NestSize::_W; x++) {
			for (int y = 0; y < NestSize::_H; y++) {
				PosX = AntNestBoad::Param::Pos_TopLeft_X + AntNestBoad::Param::SizeW * x + 10 * x;
				PosY = AntNestBoad::Param::Pos_TopLeft_Y + AntNestBoad::Param::SizeH * y + 10 * y;
				SizeW = AntNestBoad::Param::SizeW;
				SizeH = AntNestBoad::Param::SizeH;

				NestRect[x][y] = Rect{ PosX,PosY,SizeW,SizeH };
				NestRect[x][y] = Rect{ PosX,PosY,SizeW,SizeH };


				switch (NestData[x][y]) {
				case NestData::Open:
					iColor[x][y] = iColorPicker[NestData::cpOpen];
					fColor[x][y] = fColorPicker[NestData::cpOpen];
					break;
				case NestData::Close:
					iColor[x][y] = iColorPicker[NestData::cpClose];
					fColor[x][y] = fColorPicker[NestData::cpClose];
					break;
				}

			};
		}





		InitFlg = true;
	}
}

void AntNestBoad::OnClicked() {

}

