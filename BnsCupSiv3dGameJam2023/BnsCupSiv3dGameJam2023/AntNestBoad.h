#pragma once

#include "DrawWindow.h"
#include "debugMgr.h"
class AntNestBoad
{
public:
	AntNestBoad() {
		BoadClear();
	}
	void Init();

	const enum eNestBonusData {
		NONE = 0,
		ANT = 1,
		FOOD = 2,
		UnkFood = 3,
		UnkANT = 4,
		UnkEnemy = 5,

		BONUS_FOOD_POINT = 5,//とりあえず５

		PAR_NONE = 70,//7０％は何もなし
		PAR_ANT = 2,//2%はあり
		PAR_FOOD = 10,//10%はフード
		PAR_UNK_FOOD = 10,//隠れたフード
		PAR_UNK_ANT = 4,//隠れたアリ
		PAR_UNK_ENEMY = 4,

		BONUS_TYPE = 6,


	};

private:
	const enum Param{
		 SizeH = 90,
		 SizeW = 90,
		 Pos_TopLeft_X = 70,
		 Pos_TopLeft_Y = 250,//170,

		 InitPosx = 4,
		 InitPosY = 0,



		 WindowX = 100,
		 WindowY = 100,
		 WindowW = 900,
		 WindowH = 500,

		 OKWindowW = 100,
		 OKWindowH = 50,
		 OKWindowX = WindowX + WindowW - OKWindowW * 2,
		 OKWindowY = WindowY + WindowH - OKWindowH * 2,
	};

	const enum eNestData {
		Close = 0,
		Open = 1,
		canOpen = 2,
		Build = 3,

		Color_Pattern = 6,
		cpClose = 0,
		cpOpen = 1,
		cpCanOpen = 0,		//cpCloseと見た目は同じ
		cpMouseOver = 2,
		cpMouseOverCant = 3,
		cpBuildMouseOver = 4,
		cpBuild = 5,
	};
	//のちのちテクスチャーに変更するかも

	const Texture foodtex{ U"🍖"_emoji };
	const Texture AntTex{ U"🐜"_emoji };

	const enum NestSize {
		_W = 9,
		_H = 7,
	};
	Color iColorPicker[eNestData::Color_Pattern];
	Color fColorPicker[eNestData::Color_Pattern];

	Color iColor[NestSize::_W][NestSize::_H];
	Color fColor[NestSize::_W][NestSize::_H];

	int32 NestData[NestSize::_W][NestSize::_H];

	int32 NestBonusData[NestSize::_W][NestSize::_H];

	Array<int32> NestBonusParPanel;

	Rect NestRect[NestSize::_W][NestSize::_H];

	bool InitFlg = false;

	int32 HouseCnt = 0;

	bool BonusDrawFlg = false;

	int32 BonusInfotmpX = -1, BonusInfotmpY = -1;

	String BonusInfoStr[eNestBonusData::BONUS_TYPE];

	bool SearchFlg = false;

	Array<int32> BonusInfoDrawPosX, BonusInfoDrawPosY;
	bool BonusInfoDrawInitFlg = false;
	int32 _SearchtmpX, _SearchtmpY;

	int32 _OpenCnt = 0;

	bool isValid(int32 x,int32 y);

	void InitCanOpenSet(int x, int y);

	void InitBoadBonus();

	void SetBoadBonus();

	void BonusInfoDraw();

	
	//const Texture texture{U}
public:


	void Draw();
	bool OnClicked(int x,int y);
	bool MouseOveredChangeColor(bool OpenFlg);

	bool BuildOnClicked(int x, int y);
	bool BuildMouseOveredChangeColor(bool OpenFlg);

	void BoadClear();
	void BoadUpdate(int32 x,int32 y);

	void BonusInfoPopupDraw();

	bool GetBonusDrawFlg() {
		return BonusDrawFlg;
	}

	int32 SearchBonus(int32 x,int32 y);

	int32 SearchBonus();

	void BoadOpen(int x, int y) {
		NestData[x][y] = eNestData::Open;
		++_OpenCnt;
		BoadUpdate(x, y);
	}


	int32 GetHouseCnt() {
		return HouseCnt;
	}

	int32 GetOpenCnt() {
		return _OpenCnt;
	}
	DrawWindow cDrawWindow;

	void End();

	//void SearchCanOpenBlock();
	//void CheckBlockState( int32 x, int32 y);
};

