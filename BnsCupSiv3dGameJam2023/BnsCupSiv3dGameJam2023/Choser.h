#pragma once

#include "Water.h"
#include "food.h"

class Choser
{
public:
	void NestOpenButton();
	void GetFoodButton();
	void GetWaterButton();
	void BuildButton();
	void ArmyTraning();

	void Init();



	void OnClicked();
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
		atSize =70,

		InitTurnActionCnt = 4,
	};

	int32 TurnActionCount = Param::InitTurnActionCnt;

	bool InitFlg = false;
	food _FoodObj;
	Water _WaterObj;

	Circle nobCircle;
	Circle gfbCircle;
	Circle gwbCircle;
	Circle bbCircle;
	Circle atCircle;
	


};

