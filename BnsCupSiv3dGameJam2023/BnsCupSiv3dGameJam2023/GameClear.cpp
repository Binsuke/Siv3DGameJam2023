#include "stdafx.h"
#include "GameClear.h"


void GameClear::UpdateClearPoint(int32 iParentCnt, int32 iChildrenCnt, int32 iArmyCnt) {
	ClearPoint = (iParentCnt * 2 + iChildrenCnt * 1 + iArmyCnt * 2) * 2 + 15;
}

void GameClear::GameEnd(int32 iFood) {
	if (iFood >= ClearPoint) {
		//ゲームクリア
		//_Window.Draw(U"GameClear!!");
		GameClearFlg = GameClear::eGameClear::Clear;
	}
	else {
		//ゲームオーバー
		//_Window.Draw(U"GameOver");
		GameClearFlg = GameClear::eGameClear::Over;
	}

}

void GameClear::Init() {
	_Window.InitWindow(GameClear::Param::_X, GameClear::Param::_Y, GameClear::Param::_W,GameClear::Param::_H,
		GameClear::_OKX, GameClear::Param::_OKY, GameClear::Param::_OKW, GameClear::Param::_OKH);

	_Window.SetColor(ColorF(Palette::Turquoise), ColorF(0), ColorF(1), ColorF(0));

	GameClearFlg = GameClear::eGameClear::NONE;
}


void GameClear::Draw() {
	InfoDraw();
	switch (GameClearFlg) {
	case GameClear::eGameClear::NONE :
		break;
	case GameClear::eGameClear::Clear:
		_Window.Draw(U"GameClear!!");
		break;
	case GameClear::eGameClear::Over:
		_Window.Draw(U"GameOver");
		break;
	}
	
}

int32 GameClear::ReturnToTitle() {
	if (_Window.OnClicked()) {
		return 0;
	}

	return 3;
}

void GameClear::InfoDraw() {
	font(U"目標は１０月の終わりまでに余剰食料を{}個集めよう"_fmt(ClearPoint)).draw(30,50, 50, ColorF(Palette::Black));
}
