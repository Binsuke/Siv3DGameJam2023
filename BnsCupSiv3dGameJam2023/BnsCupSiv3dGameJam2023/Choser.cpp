
#include "stdafx.h"

#include "Choser.h"
#include "debugMgr.h"

void Choser::NestOpenButton() {
	if (InitFlg) {
		nobCircle.draw(ColorF(0.3, 0.7, 1.0));
		nobCircle.drawFrame(2, ColorF(0.1));
	}
}


void Choser::GetFoodButton() {
	if (InitFlg) {
		gfbCircle.draw(ColorF(0.5, 0.7, 1.0));
		gfbCircle.drawFrame(2, ColorF(0.1));
	}
}


void Choser::GetWaterButton() {
	if (InitFlg) {
		gwbCircle.draw(ColorF(0.7, 0.7, 1.0));
		gwbCircle.drawFrame(2, ColorF(0.1));
	}
}


void Choser::BuildButton() {
	if (InitFlg) {
		bbCircle.draw(ColorF(0.7, 0.5, 0.2));
		bbCircle.drawFrame(2, ColorF(0.1));
	}
}

void Choser::ArmyTraning() {
	if (InitFlg) {
		atCircle.draw(ColorF(1.0, 0.1, 0.1));
		atCircle.drawFrame(2, ColorF(0.1));
	}
}



void Choser::Init() {
	Circle circle{ Choser::Param::NestOpenButtonX + Choser::Param::nobSize / 2,Choser::NestOpenButtonY + Choser::Param::nobSize / 2, Choser::Param::nobSize };

	nobCircle = circle;

	Circle circle2{ Choser::Param::gfbX + Choser::Param::gfbSize / 2 ,Choser::Param::gfbY + Choser::Param::gfbSize / 2 ,Choser::Param::gfbSize };

	gfbCircle = circle2;


	Circle circle3{ Choser::Param::gwbX + Choser::Param::gwbSize / 2 , Choser::Param::gfbY + Choser::Param::gwbSize / 2 ,Choser::Param::gwbSize };

	gwbCircle = circle3;

	Circle circle4{ Choser::Param::bbX + Choser::Param::bbSize / 2 , Choser::Param::bbY + Choser::Param::bbSize / 2 , Choser::Param::bbSize };

	bbCircle = circle4;

	Circle circle5{ Choser::Param::atX + Choser::Param::atSize / 2 ,Choser::Param::atY + Choser::Param::atSize / 2,Choser::Param::atSize };
	atCircle = circle5;

	InitFlg = true;
}


void Choser::OnClicked() {
	//行動権が残っていたら
	if (TurnActionCount > 0) {
		if (gfbCircle.leftClicked()) {
			_FoodObj.SearchFood();

			--TurnActionCount;
		}
		if (gwbCircle.leftClicked()) {
			_WaterObj.SearchWater();

			--TurnActionCount;
		}
	}
	ClearPrint();
	DebugPrint(TurnActionCount, U"残り手番");

	
}
