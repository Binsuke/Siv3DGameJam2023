﻿#pragma once

#include "Resource.h"
#include "food.h"
#include "Army.h"
#include "AntNestBoad.h"
#include "Enemy.h"
#include "DrawWindow.h"
#include "SceneInterface.h"
#include "GameClear.h"
//#include "Sccene.h"
class Choser : public SceneInterface
{
public:
	

	void Init() override;

	void Draw() override;


	int32 Run() override;

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

		marX = 100,
		marY = 100,
		marW = 900,
		marH = 500,

		marOKW = 100,
		marOKH = 50,
		marOKX = marX + marW - marOKW * 2,
		marOKY = marY + marH - marOKH * 2,

		BottunInfoX = 100,
		BottunInfoY = 50,

		BottunInfoW = 1100,
		BottunInfoH = 80,

		StartMonth = 6,
		EndMonth = 5,
	};

	const enum Bonus {
		BonusFoodPoint = 3,
	};
	const Texture foodtex{ U"texture/food.png" };//{ U"🍖"_emoji };
	const Texture AntTex{ U"texture/ant.png" };//{ U"🐜"_emoji };
	const Texture BabyTex{ U"texture/baby.png" };
	const Texture ArmyTex{ U"texture/Army.png" };//{ U"💂"_emoji };
	const Texture HouseTex{ U"🏠"_emoji };
	const Texture NextFoodTex{ U"🍴"_emoji };
	const Texture NextEnemyTex{ U"☠"_emoji };

	const Texture FoodSeachTex{ U"texture/research.png" };
	const Texture HoruTex{ U"texture/horu.png" };
	const Texture BuildTex{ U"texture/build.png" };
	const Texture EggTex{ U"texture/egg.png" };
	const Texture ArmyTraningTex{ U"texture/Army.png" };
	const Texture QueenTex{ U"texture/Queen.png" };
	//Rect NextMonthRectIn;
	//Rect NextMonthRectOut;
	const Font font{ FontMethod::MSDF,48 };

	
	int32 WeekCnt = 0;//何週間目かの確認用
	int32 WeekTurnMax;//１週間にできる手番の数
	int32 MonthCnt = 0;

	int32 TurnActionCount = Param::InitTurnActionCnt;

	int32 mGetFood = 0, mLostFood = 0,mLostFoodEnemy = 0, mLostArmy = 0, mLostResource = 0;

	bool MonthResultFlg = false;
	//初期化フラグ
	bool InitFlg = false;

	bool MonthActionFlg = false;
	bool MonthStartFlg = false;
	//各関数オブジェクト
	food _FoodObj;
	cResource _ResourceObj;
	Army _ArmyObj;
	AntNestBoad _NestObj;
	Enemy _EnemyObj;

	GameClear _GameClearObj;

	bool orpNestOpenFlg = false, orpGFBFlg = false, orpGRBFlg = false, orpAtFlg = false, orpBBFlg = false;

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

	//リザルト用
	Rect marRect;
	Rect marOKRect;

	//ボタンのインフォーメーション用
	DrawWindow BottunInfoWindow;

	//Function
	void OnClicked();
	int32 TurnAdm();

	void InfoDraw();
	void NestOpenButton();
	void GetFoodButton();
	void GetResourceButton();
	void BuildButton();
	void ArmyTraning();

	void MonthAction();
	void MonthActionResultSet(int32 GetFood,int32 LostFood,int32 LostFoodEnemy,int32 LostArmy,int32 LostResource);
	bool MonthActionResultDraw();

	void UpdateNextFoodPoint();

	void MonthStartStatusSet();
	void MonthStartStatusDraw();

	void DrawInfoGrid(ColorF inColor,ColorF outColor,ColorF inColor2,ColorF outColor2);

	void BonusFunc();

	void BottunInitWindow();

	void BottunOverrideMgr();

	void gfbDrawInfo();
	void nobDrawInfo();
	void grbDrawInfo();
	void bbDrawInfo();
	void atDrawInfo();
	void UpdateTrunAction();
};

