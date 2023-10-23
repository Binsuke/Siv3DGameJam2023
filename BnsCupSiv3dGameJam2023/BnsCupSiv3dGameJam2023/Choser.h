#pragma once

#include "Resource.h"
#include "food.h"
#include "Army.h"
#include "AntNestBoad.h"
#include "Enemy.h"

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
		NestOpenButtonY = 130,
		NestOpenButtonX = 70,//300,
		nobSize = 70,

		gfbY = 130,
		gfbX = Param::NestOpenButtonX + 150,
		gfbSize = 70,

		grbY = 130,
		grbX = Param::gfbX + 150,
		grbSize = 70,

		bbY = 130,
		bbX = Param::grbX + 150,
		bbSize = 70,

		atY = 130,
		atX = Param::bbX + 150,
		atSize = 70,

		InitTurnActionCnt = 4,

		DefaultFoodWeight = 4,
		Ant_FoodWeight = 2,
		_true = 1,
		_false = 0,
	};

	const Texture foodtex{ U"🍖"_emoji };
	const Texture AntTex{ U"🐜"_emoji };
	const Texture ArmyTex{ U"💂"_emoji };
	const Texture HouseTex{ U"🏠"_emoji };
	const Texture NextFoodTex{ U"🍴"_emoji };
	const Texture NextEnemyTex{ U"☠"_emoji };


	//Rect NextMonthRectIn;
	//Rect NextMonthRectOut;
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
	Enemy _EnemyObj;


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

