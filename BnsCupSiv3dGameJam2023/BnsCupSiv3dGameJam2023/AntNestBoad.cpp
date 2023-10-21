#include "stdafx.h"
#include "AntNestBoad.h"


void AntNestBoad::Draw()
{
	Color iColor[2] = { ColorF(0.7), ColorF(0.1) };

	Color fColor[2] = { ColorF(0.6), ColorF(0.2) };

	int32 PosX, PosY, SizeW, SizeH;
	for (int x = 0; x < NestSize::_W; x++) {
		for (int y = 0; y < NestSize::_H; y++) {
			PosX = AntNestBoad::Param::Pos_TopLeft_X + AntNestBoad::Param::SizeW * x + 10 * x;
			PosY = AntNestBoad::Param::Pos_TopLeft_Y + AntNestBoad::Param::SizeH * y + 10 * y;
			SizeW = AntNestBoad::Param::SizeW;
			SizeH = AntNestBoad::Param::SizeH;

			Rect{ PosX,PosY,SizeW,SizeH }.draw(iColor[NestData[x][y]]);
			Rect{ PosX,PosY,SizeW,SizeH }.drawFrame(5,5,fColor[NestData[x][y]]);

		};


			//Rect{ AntNestBoad::Param::Pos_TopLeft_X + AntNestBoad::Param::SizeW * x,AntNestBoad::Param::Pos_TopLeft_Y+ AntNestBoad::Param::SizeH,AntNestBoad::Param::SizeW,AntNestBoad::Param::SizeH }.draw(ColorF(0.7));
			//Rect{ AntNestBoad::Param::Pos_TopLeft_X,AntNestBoad::Param::Pos_TopLeft_Y,AntNestBoad::Param::SizeW,AntNestBoad::Param::SizeH }.drawFrame(5, 5, ColorF(0.2));
		
	}

}
