#pragma once
#include "DrawWindow.h"
class GameClear
{
private:
	enum Param {
		_X = 100,
		_Y = 100,
		_W = 1000,
		_H = 800,
		_OKX = _X + _W /2,
		_OKY = _Y + _H /2,
		_OKW = 200,
		_OKH = 50,
	};

	enum eGameClear {
		NONE = 0,
		Clear = 1,
		Over = 2,
	};
	int32 ClearPoint;
	DrawWindow _Window;
	int32 GameClearFlg = GameClear::eGameClear::NONE;

	const Font font{ FontMethod::MSDF,48 };
public:
	void UpdateClearPoint(int32 iParentCnt, int32 iChildrenCnt, int32 iArmyCnt);

	void GameEnd(int32 iFood);

	void Init();

	void Draw();

	void InfoDraw();

	int32 ReturnToTitle();
};

