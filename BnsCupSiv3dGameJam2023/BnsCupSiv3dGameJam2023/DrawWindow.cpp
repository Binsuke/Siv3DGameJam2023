#include "stdafx.h"
#include "DrawWindow.h"


void DrawWindow::InitWindow(int32 iX, int32 iY, int32 iW, int32 iH,int32 iOKX,int32 iOKY,int32 iOKW,int32 iOKH) {
	_X = iX;
	_Y = iY;
	_W = iW;
	_H = iH;
	_OKX = iOKX;
	_OKY = iOKY;
	_OKW = iOKW;
	_OKH = iOKH;
	_RectWindow = Rect(_X,_Y, _W,_H);
	_RectOKWindow = Rect(_OKX, _OKY, _OKW, _OKH);
}

void DrawWindow::InitWindow(int32 iX, int32 iY, int32 iW, int32 iH) {
	_X = iX;
	_Y = iY;
	_W = iW;
	_H = iH;
	_RectWindow = Rect(_X, _Y, _W, _H);
}

void DrawWindow::Draw( String str) {
	_RectWindow.draw(_WindowInColor);
	_RectWindow.drawFrame(5,_WindowOutColor);

	_RectOKWindow.draw(_OKWindowInColor);
	_RectOKWindow.drawFrame(5,_OKWindowOutColor);


	font(U"{}"_fmt(str)).draw(50, _X + 30, _Y + 100);

	DrawFlg = true;
}


void DrawWindow::DrawWindowOnly(String str) {
	_RectWindow.draw(_WindowInColor);
	_RectWindow.drawFrame(5, _WindowOutColor);

	font(U"{}"_fmt(str)).draw(50, _X + 30, _Y + 100);
}


void DrawWindow::DrawWindowOnly(String str,int32 StrSize) {
	_RectWindow.draw(_WindowInColor);
	_RectWindow.drawFrame(5, _WindowOutColor);

	font(U"{}"_fmt(str)).draw(StrSize, _X + 30, _Y + 100);
}


void DrawWindow::DrawWindowOnly(String str, int32 StrSize,int32 offsetX,int32 offsetY) {
	_RectWindow.draw(_WindowInColor);
	_RectWindow.drawFrame(5, _WindowOutColor);

	font(U"{}"_fmt(str)).draw(StrSize, _X + offsetX, _Y + offsetY);
}


bool DrawWindow::OnClicked() {
	if (DrawFlg) {
		if (_RectOKWindow.leftClicked()) {
			MouseL.clearInput();
			DrawFlg = false;
			return true;
		}
	}
	return false;
}
