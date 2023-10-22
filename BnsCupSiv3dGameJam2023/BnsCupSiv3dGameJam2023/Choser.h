#pragma once

#include "Water.h"
#include "food.h"
#include "Army.h"
#include "AntNestBoad.h"

class Choser
{
public:
	void NestOpenButton();
	void GetFoodButton();
	void GetWaterButton();
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

		gwbY = 50,
		gwbX = 350,
		gwbSize = 70,

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

	int32 TurnActionCount = Param::InitTurnActionCnt;
	//初期化フラグ
	bool InitFlg = false;
	//各関数オブジェクト
	food _FoodObj;
	Water _WaterObj;
	Army _ArmyObj;
	AntNestBoad _NestObj;

	//ネストオープンボタンのアクティブと非アクティブの色変化
	Color NestOpenButtonColor[2];

	//ネストオープンボタンのアクティブ、非アクティブ判定用フラグ
	bool NestOpenFlg;

	//ボタンサークル
	Circle nobCircle;
	Circle gfbCircle;
	Circle gwbCircle;
	Circle bbCircle;
	Circle atCircle;

	//Function
	void OnClicked();


};

