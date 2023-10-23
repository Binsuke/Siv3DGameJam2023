
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


void Choser::GetResourceButton() {
	if (InitFlg) {
		grbCircle.draw(ColorF(0.7, 0.7, 1.0));
		grbCircle.drawFrame(2, ColorF(0.1));
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

		//DebugPrint(NestBuildButtonColor[tmp], U"ビルドボタンカラー");
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
	GetResourceButton();
	BuildButton();
	ArmyTraning();
	_NestObj.Draw();
	InfoDraw();
}



void Choser::Init() {
	Circle circle{ Choser::Param::NestOpenButtonX + Choser::Param::nobSize / 2,Choser::NestOpenButtonY + Choser::Param::nobSize / 2, Choser::Param::nobSize };

	nobCircle = circle;

	Circle circle2{ Choser::Param::gfbX + Choser::Param::gfbSize / 2 ,Choser::Param::gfbY + Choser::Param::gfbSize / 2 ,Choser::Param::gfbSize };

	gfbCircle = circle2;


	Circle circle3{ Choser::Param::grbX + Choser::Param::grbSize / 2 , Choser::Param::gfbY + Choser::Param::grbSize / 2 ,Choser::Param::grbSize };

	grbCircle = circle3;

	Circle circle4{ Choser::Param::bbX + Choser::Param::bbSize / 2 , Choser::Param::bbY + Choser::Param::bbSize / 2 , Choser::Param::bbSize };

	bbCircle = circle4;

	Circle circle5{ Choser::Param::atX + Choser::Param::atSize / 2 ,Choser::Param::atY + Choser::Param::atSize / 2,Choser::Param::atSize };
	atCircle = circle5;

	

	NestOpenButtonColor[Choser::Param::_false] = ColorF(0.3, 0.7, 1.0);

	NestOpenButtonColor[Choser::Param::_true] = ColorF(1.0, 0.7, 1.0);

	NestBuildButtonColor[Choser::Param::_false] = ColorF(0.7, 0.5, 0.2);

	NestBuildButtonColor[Choser::Param::_true] = ColorF(1.0, 0.5, 0.2);


	NestOpenFlg = false;

	WeekTurnMax = Choser::Param::InitTurnActionCnt;

	_NestObj.Init();

	_FoodObj.SetNextFoodPoint(Choser::Param::DefaultFoodWeight);

	_EnemyObj.SetNextEnemyCount(2);

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
		//子供ボタンクリック
		if (grbCircle.leftClicked()) {
			if ((_ResourceObj.GetResouceCnt() + _ArmyObj.GetArmyCnt()) < _NestObj.GetHouseCnt()) {
				_ResourceObj.SearchResource();
				_FoodObj.AddNextFoodPoint(Choser::Param::Ant_FoodWeight / 2);//子供なので
				--TurnActionCount;
			}
		}
		//アーミートレーニングサークルクリック
		if (atCircle.leftClicked()) {
			if (_ResourceObj.GetResouceCnt() > 0) {
				_ArmyObj.ArmyTraningOnClicked();
				_ResourceObj.UseResource();
				--TurnActionCount;
			}
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
		//ビルドオープンボタン実装
		if (_NestObj.BuildMouseOveredChangeColor(NestBuildFlg)) {
			--TurnActionCount;
			NestBuildFlg = false;
		}
		//DebugPrint(NestBuildFlg, U"ネストビルドフラグ");
	}
	
	//DebugPrint(TurnActionCount, U"残り手番");

	
}


void Choser::TurnAdm() {
	if (TurnActionCount == 0) {
		++WeekCnt;
		TurnActionCount = WeekTurnMax;
	}
	if (WeekCnt % 4 == 0 && WeekCnt != 0) {
		Print << U"一か月経過";
		//DebugPrint(WeekCnt, U"WeekCnt");
	}
}

void Choser::Run() {
	OnClicked();

	TurnAdm();
}


void Choser::InfoDraw() {
	


	foodtex.scaled(0.5).drawAt(1030, 300);
	font(U"{}"_fmt(_FoodObj.GetFoodCnt())).draw(50, 1065, 275);

	AntTex.scaled(0.5).drawAt(1030, 375);
	font(U"{}"_fmt(_ResourceObj.GetResouceCnt())).draw(50, 1065, 350);

	ArmyTex.scaled(0.5).drawAt(1030,450);
	font(U"{}"_fmt(_ArmyObj.GetArmyCnt())).draw(50, 1065, 425);

	HouseTex.scaled(0.5).drawAt(1030, 525);
	font(U"{}"_fmt(_NestObj.GetHouseCnt())).draw(50, 1065, 500);


	font(U"{}月{}週目:残り手番{}回"_fmt((WeekCnt / 4)+1, (WeekCnt % 4)+1, TurnActionCount)).draw(50, 50, 10);



	Rect{ 800,35,400,200 }.draw(Palette::Aqua);
	Rect{ 800,35,400,200 }.drawFrame(5,Palette::Deepskyblue);

	Rect{ 800,35,400,80 }.draw(Palette::Skyblue);
	Rect{ 800,35,400,80 }.drawFrame(5,Palette::Deepskyblue);


	NextFoodTex.scaled(0.7).drawAt(930, 170);
	font(U"{}"_fmt(_FoodObj.GetNextNeedFoodPoint())).draw(50, 970, 140);

	NextEnemyTex.scaled(0.7).drawAt(1080, 175);
	font(U"{}"_fmt(_EnemyObj.GetCount())).draw(50, 1130, 140);


	font(U"月末の予定").draw(50, 810, 40);
}
