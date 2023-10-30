﻿
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
	MonthActionResultDraw();
	MonthStartStatusDraw();
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

	Rect rect{ Choser::Param::marX,Choser::Param::marY,Choser::Param::marW,Choser::Param::marH };

	marRect = rect;

	Rect rect2{ Choser::Param::marOKX,Choser::Param::marOKY,Choser::Param::marOKW,Choser::Param::marOKH };

	marOKRect = rect2;

	NestOpenButtonColor[Choser::Param::_false] = ColorF(0.3, 0.7, 1.0);

	NestOpenButtonColor[Choser::Param::_true] = ColorF(1.0, 0.7, 1.0);

	NestBuildButtonColor[Choser::Param::_false] = ColorF(0.7, 0.5, 0.2);

	NestBuildButtonColor[Choser::Param::_true] = ColorF(1.0, 0.5, 0.2);


	NestOpenFlg = false;

	WeekTurnMax = Choser::Param::InitTurnActionCnt;

	_NestObj.Init();

	_FoodObj.SetNextFoodPoint(Choser::Param::DefaultFoodWeight);

	MonthStartStatusSet();//月初めのステータスの設定

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
				//_FoodObj.AddNextFoodPoint(Choser::Param::Ant_FoodWeight / 2);//子供なので
				UpdateNextFoodPoint();
				--TurnActionCount;
			}
		}
		//アーミートレーニングサークルクリック
		if (atCircle.leftClicked()) {
			if (_ResourceObj.GetResourceParentCnt() > 0) {//大人のアリがいたら押せる
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
		if (MonthActionFlg == false) {
			MonthActionFlg = true;
			MonthAction();
			MonthStartStatusSet();
			//DebugPrint(MonthActionFlg, U"WeekActionFlg");

		}
		//MonthAction();
	}
	if (WeekCnt %4  == 1 && WeekCnt != 0 && WeekCnt != 1) {
		if (MonthActionFlg == true) {
			MonthActionFlg = false;
		}
		DebugPrint(MonthActionFlg, U"WeekActionFlg");
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


void Choser::MonthAction() {

	//最初に兵の計算
	int32 GetFood = 0, LostFood = 0, LostFoodEnemy= 0,LostArmy = 0, LostResource = 0;
	if (_ArmyObj.GetArmyCnt() >= _EnemyObj.GetCount()) {//兵の数が敵以上だった場合

		_FoodObj.AddFood(_EnemyObj.GetCount());//敵の数を食料に追加

		GetFood = _EnemyObj.GetCount();//リザルト表示用変数に格納

		int32 Battletmp = _ArmyObj.GetArmyCnt() - _EnemyObj.GetCount();//敵の数と兵隊の数を比較して

		int RandamTmp = Random(100);

		if (25 * Battletmp + 50 < RandamTmp) {//数が多くなれば兵隊が減る確率がなくなる　起訴確率が５０％

			LostArmy += 1;
			_ArmyObj.DecArmy();	//確率で兵隊ありが一匹減少
			UpdateNextFoodPoint();
		}
	}
	else {//兵の数が敵以下だった場合
		if ((_EnemyObj.GetCount() * 2) <= _FoodObj.GetFoodCnt()) {//兵の数が足りなかった場合　食料が要求される食料以上だったら
			_FoodObj.DecFood(_EnemyObj.GetCount() * 2);//敵の数＊２の食料を渡す
			LostFoodEnemy = _EnemyObj.GetCount() * 2;//失った食料のリザルト用変数
		}
		else {								//食料が足りなかった場合自分のアリが減少
			//int32 EnemyNeedFoodPoint = _EnemyObj.GetCount() - _FoodObj.GetFoodCnt() / 2;//食料分減少を減らす
			int32 tmp = _ArmyObj.GetArmyCnt() -_EnemyObj.GetCount();//まずは兵隊ありの数を減らした場合の残りいくつマイナスなのかを保存しておく


			LostArmy += _ArmyObj.GetArmyCnt();//減らす前にhらした兵士の数のリザルトを変数に足しこむ

			//兵士の数は足りないのでまずは兵士の数を減らす
			_ArmyObj.DecArmy(_ArmyObj.GetArmyCnt());

			//残りのマイナス分の計算をしないといけないので

			if (tmp < 0) {//一応計算された数値がマイナスかを確認
				tmp *= -1;//プラスマイナスを反転
			}
			
			int32 tmp2;// = _ResourceObj.GetResouceCnt() - tmp;//残りのアリの数から引いてあげる

			//if (tmp2 < 0){//マイナス以下にはできないので補正 
			//	tmp2 = 0;
			//}

			if (_ResourceObj.GetResouceCnt() - tmp <= 0) {
				LostResource += _ResourceObj.GetResouceCnt();//失うアリの数が多すぎた場合はすべてのアリを失うのをリザルトに入れる
				tmp2 = _ResourceObj.GetResouceCnt();//減らす数を表示
			}
			else {
				LostResource += tmp;//生き残りがいる場合は減少する数をリザルト表示用に追加する
				tmp2 = tmp;//減らす数を変数に格納
			}
			_ResourceObj.DecResource(tmp2);//テンプをセット　　＊ここの使用をリソースクラスをキュー構造にして先いれ先出し構造にしたい
																//そうすることで大人を優先的に減少できる

			UpdateNextFoodPoint();
		}
	}
	//キリギリスの処理が終わったら
	//食料消費フェーズ
	if (_FoodObj.GetFoodCnt() >= _FoodObj.GetNextNeedFoodPoint()) {//月末に必要なNextNeedFoodPointより食料があれば
		int32 tmp = _FoodObj.GetFoodCnt() - _FoodObj.GetNextNeedFoodPoint();//食料を消費して
		LostFood += _FoodObj.GetNextNeedFoodPoint();						//食料消費量のリザルト表示用変数に追加
		_FoodObj.SetFood(tmp);												//食料の数を再セット
	}
	else {//食料が足りなかった場合
		int32  NotEnoughFoodPoint = (_FoodObj.GetNextNeedFoodPoint() - _FoodObj.GetFoodCnt());// / 2;//足りない食料の数に対するポイントを設定
																								//２で割っているのは大人のアリの食料消費が２に設定されているので
																								//子供一人分は計算から除外する
		//if (NotEnoughFoodPoint == 0) {//ただし食料消費が子供一人分足りない場合は０ではなく１ポイントに修正
		//	NotEnoughFoodPoint = 1;
		//}

		int32 tmp = _ArmyObj.GetArmyCnt() - NotEnoughFoodPoint;//足りないポイントと兵隊の数を比較するためにいれる

		if (tmp >= 0) {//兵隊の数で減少が足りるなら兵隊の数だけとりあえず減らす
			LostArmy += NotEnoughFoodPoint;//リザルト表示用変数に減少量を足しこむ
			_ArmyObj.DecArmy(NotEnoughFoodPoint);
		}
		else {//兵隊の数で足りないなら
			tmp *= -1;//数値を反転
			LostArmy += _ArmyObj.GetArmyCnt();//兵隊の数をすべて失った数に足しこむ
			_ArmyObj.DecArmy(_ArmyObj.GetArmyCnt());//兵隊をまずは０にする

			int32 tmp2;// = _ResourceObj.GetResouceCnt() - tmp;//一般アリの数から兵隊数を減らしたうえで足りないポイント数の比較用
			//if (tmp2 < 0) {//マイナスになるようなら０に補正
			//	tmp2 = 0;
			//}
			if (_ResourceObj.GetResouceCnt() - tmp <= 0) {//リソース以上の減少の場合は補正して減少させる
				LostResource += _ResourceObj.GetResouceCnt();
				tmp2 = _ResourceObj.GetResouceCnt();//全部のアリが死ぬのでその数をセット
			}
			else {
				LostResource += tmp;
				tmp2 = tmp;//全部死なない場合はその数を変数に格納
			}

			_ResourceObj.DecResource(tmp2);//その後全体からアリを減らす

		}
		UpdateNextFoodPoint();//処理が終わったら必要な食料のアップデート
	}
	MonthActionResultSet(GetFood, LostFood, LostFoodEnemy,LostArmy, LostResource);
}


void Choser::UpdateNextFoodPoint() {

	int32 tmp = _ArmyObj.GetArmyCnt() * 2 + _ResourceObj.GetNeedFood() + Choser::Param::DefaultFoodWeight;
	_FoodObj.SetNextFoodPoint(tmp);
}

void Choser::MonthActionResultSet(int32 iGetFood, int32 iLostFood, int32 iLostFoodEnemy,int32 iLostArmy, int32 iLostResource) {
	mGetFood = iGetFood;
	mLostFood = iLostFood;
	mLostFoodEnemy = iLostFoodEnemy;
	mLostArmy = iLostArmy;
	mLostResource = iLostResource;
	MonthResultFlg = true;
}

bool Choser::MonthActionResultDraw() {
	if (MonthResultFlg) {
		marRect.draw(ColorF(Palette::Skyblue));
		marRect.drawFrame(5,ColorF(Palette::Darkblue));

		marOKRect.draw(ColorF(0.9));
		marOKRect.drawFrame(5,ColorF(1.0));

		
		font(U"月末の獲得食料の数:{}"_fmt(mGetFood)).draw(50, marX + 30, marY + 100);

		font(U"消費食料の数(アリ:{},敵に譲渡:{})"_fmt(mLostFood,mLostFoodEnemy)).draw(50, marX + 30, marY + 150);

		font(U"月末の失った兵隊アリの数:{}"_fmt(mLostArmy)).draw(50,marX + 30,marY + 200);

		font(U"月末の失った一般アリの数:{}"_fmt(mLostResource)).draw(50,marX +30, marY + 250);

		if (marOKRect.leftClicked()) {
			MouseL.clearInput();
			MonthResultFlg = false;
		}
	}

	return false;
}


void Choser::MonthStartStatusSet() {//月の初めの様々なステータスを決定する

	int Randomtmp;//0~5の値を入手

	if (WeekCnt <= 12) {//３か月までは
		Randomtmp = Random(100) % 3;//最大2の値
	}
	else {
		Randomtmp = Random(100) % 8;//仮
	}

	_EnemyObj.SetNextEnemyCount(Randomtmp);

	MonthStartFlg = true;
}


void Choser::MonthStartStatusDraw() {
	if (MonthStartFlg == true && MonthResultFlg == false) {
		DrawInfoGrid(ColorF(Palette::Darkblue), ColorF(Palette::Skyblue), ColorF(0.9), ColorF(0.1));

		font(U"月末に襲ってくる敵の数は:{}"_fmt(_EnemyObj.GetCount())).draw(50, marX + 30, marY + 100);

		if (marOKRect.leftClicked()) {
			MouseL.clearInput();
			MonthStartFlg = false;
		}
	}

}


void Choser::DrawInfoGrid(ColorF inColor, ColorF outColor,ColorF inColor2,ColorF outColor2) {
	marRect.draw(inColor);
	marRect.drawFrame(5,outColor);

	marOKRect.draw(inColor2);
	marOKRect.drawFrame(5,outColor2);
}

//.upで取れる
