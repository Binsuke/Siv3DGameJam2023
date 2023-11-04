#include "stdafx.h"
#include "Title.h"


void Title::WindowInit() {
	Window.InitWindow(Title::Param::_X, Title::Param::_Y, Title::Param::_W, Title::Param::_H);
	Window.SetColor(ColorF(Palette::Aliceblue), ColorF(1));


	GameStartBottun = Rect(_gsX, _gsY, _gsW, _gsH);
}

void Title::Init() {
	WindowInit();
}

void Title::Draw() {
	Window.DrawWindowOnly(U"ありときりぎりす",ColorF(0));
	GameStartBottun.draw(ColorF(Palette::Black));
	GameStartBottun.drawFrame(5, ColorF(Palette::White));

	font(U"GameStart").draw(25,_gsX + 10 , _gsY + 5 , ColorF(Palette::White));
}

int32 Title::Run() {
	if (GameStartBottun.leftClicked()) {
		return	1;//cScene::eSceneParam::sChoser;
	}
	return 3;//cScene::eSceneParam::sNoChange;
}
