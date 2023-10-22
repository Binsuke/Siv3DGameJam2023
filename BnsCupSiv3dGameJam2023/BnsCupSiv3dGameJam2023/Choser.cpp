
#include "stdafx.h"

#include "Choser.h"
#include "debugMgr.h"

void Choser::NestOpenButton() {
	if (InitFlg) {
		int32 tmp = 0;
		if (NestOpenFlg) {
			tmp = Choser::Param:: _true;
		}
		else {
			tmp = Choser::Param::_false;
		}
		nobCircle.draw(NestOpenButtonColor[tmp]);
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
		int32 tmp = 0;
		if (NestBuildFlg) {
			tmp = Choser::Param::_true;
		}
		else {
			tmp = Choser::Param::_false;
		}
		bbCircle.draw(NestBuildButtonColor[tmp]);
		bbCircle.drawFrame(2, ColorF(0.1));

		DebugPrint(NestBuildButtonColor[tmp], U"ビルドボタンカラー");
	}
}

void Choser::ArmyTraning() {
	if (InitFlg) {
		atCircle.draw(ColorF(1.0, 0.1, 0.1));
		atCircle.drawFrame(2, ColorF(0.1));
	}
}

void Choser::Draw()
{
	NestOpenButton();
	GetFoodButton();
	GetWaterButton();
	BuildButton();
	ArmyTraning();
	_NestObj.Draw();
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

	

	NestOpenButtonColor[Choser::Param::_false] = ColorF(0.3, 0.7, 1.0);

	NestOpenButtonColor[Choser::Param::_true] = ColorF(1.0, 0.7, 1.0);

	NestBuildButtonColor[Choser::Param::_false] = ColorF(0.7, 0.5, 0.2);

	NestBuildButtonColor[Choser::Param::_true] = ColorF(1.0, 0.5, 0.2);


	NestOpenFlg = false;

	_NestObj.Init();

	InitFlg = true;
}


void Choser::OnClicked() {

	ClearPrint();
	//行動権が残っていたら
	if (TurnActionCount > 0) {
		//食べ物の調達ボタンクリック
		if (gfbCircle.leftClicked()) {
			_FoodObj.SearchFood();

			--TurnActionCount;
		}
		//水の調達ボタンクリック
		if (gwbCircle.leftClicked()) {
			_WaterObj.SearchWater();

			--TurnActionCount;
		}
		//アーミートレーニングサークルクリック
		if (atCircle.leftClicked()) {
			_ArmyObj.ArmyTraningOnClicked();

			--TurnActionCount;
		}
		//ネストオープンサークルクリック
		if (nobCircle.leftClicked()) {
			
			switch(NestOpenFlg) {
				case false:
					NestOpenFlg = true;
					break;
				case true:
					NestOpenFlg = false;
					break;
			}
			
			DebugPrint(NestOpenFlg, U"NestOpenFlg");
		}
		//Nestの実際のオープン関係関数　マウスオーバーの色変化＋マウスクリック
		if (_NestObj.MouseOveredChangeColor(NestOpenFlg)) {
			--TurnActionCount;
			NestOpenFlg = false;
		}

		if (bbCircle.leftClicked()) {
			switch (NestBuildFlg) {
			case false:
				NestBuildFlg = true;
				break;
			case true:
				NestBuildFlg = false;
				break;
			}
		}
		DebugPrint(NestBuildFlg, U"ネストビルドフラグ");
	}
	
	DebugPrint(TurnActionCount, U"残り手番");

	
}


void Choser::Run() {
	OnClicked();

	//_NestObj.MouseOveredChangeColor(NestOpenFlg);
}
