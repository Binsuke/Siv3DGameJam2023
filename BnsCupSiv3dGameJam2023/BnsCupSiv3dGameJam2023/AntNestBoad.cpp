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

		fColorPicker[eNestData::cpClose] = ColorF(0.2);
		fColorPicker[eNestData::cpOpen] = ColorF(0.6);
		fColorPicker[eNestData::cpMouseOver] = ColorF(0.3);

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
				}

			};
		}

		InitFlg = true;
	}
}

void AntNestBoad::OnClicked() {

}

void AntNestBoad::MouseOveredChangeColor(bool OpenFlg) {

	if (OpenFlg) {
		for (int x = 0; x < NestSize::_W; x++) {
			for (int y = 0; y < NestSize::_H; y++) {
				if (NestRect[x][y].mouseOver()) {
					iColor[x][y] = iColorPicker[eNestData::cpMouseOver];
					fColor[x][y] = fColorPicker[eNestData::cpMouseOver];
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
					}
				}
			}
		}
	}
}

