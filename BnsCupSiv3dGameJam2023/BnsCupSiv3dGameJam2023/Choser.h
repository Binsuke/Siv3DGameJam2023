#pragma once

#include "Resource.h"
#include "food.h"
#include "Army.h"
#include "AntNestBoad.h"

class Choser
{
public:
	void NestOpenButton();
	void GetFoodButton();
	void GetResourceButton();
	void BuildButton();
	void ArmyTraning();

	void Init();

	void Draw();


	void Run();

private:
	const enum Param {
		NestOpenButtonY = 50,
		NestOpenButtonX = 50,
		nobSize = 70,

		gfbY = 50,
		gfbX = 200,
		gfbSize = 70,

		grbY = 50,
		grbX = 350,
		grbSize = 70,

		bbY = 50,
		bbX = 500,
		bbSize = 70,

		atY = 50,
		atX = 650,
		atSize = 70,

		InitTurnActionCnt = 4,

		_true = 1,
		_false = 0,
	};

	const Texture foodtex{ U"🍖"_emoji };
	const Texture AntTex{ U"🐜"_emoji };
	const Texture ArmyTex{ U"💂"_emoji };
	const Texture HouseTex{ U"🏠"_emoji };

	const Font font{ FontMethod::MSDF,48 };

	
	int32 WeekCnt = 0;//何週間目かの確認用
	int32 WeekTurnMax;//１週間にできる手番の数

	int32 TurnActionCount = Param::InitTurnActionCnt;
	//初期化フラグ
	bool InitFlg = false;
	//各関数オブジェクト
	food _FoodObj;
	cResource _ResourceObj;
	Army _ArmyObj;
	AntNestBoad _NestObj;


	//ネストオープンボタンのアクティブと非アクティブの色変化
	Color NestOpenButtonColor[2];

	//ネストオープンボタンのアクティブ、非アクティブ判定用フラグ
	bool NestOpenFlg;

	//ネストビルドボタンのアクティブと非アクティブのカラー
	Color NestBuildButtonColor[2];

	//ビルドフラグ
	bool NestBuildFlg = false;

	//ボタンサークル
	Circle nobCircle;
	Circle gfbCircle;
	Circle grbCircle;
	Circle bbCircle;
	Circle atCircle;

	//Function
	void OnClicked();
	void TurnAdm();

	void InfoDraw();
};

