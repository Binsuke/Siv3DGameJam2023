#pragma once
#include "DrawWindow.h"
#include "SceneInterface.h"
//#include "Sccene.h"
//#include "Sccene.h"
class Title : public SceneInterface
{
private:
	DrawWindow Window;
	enum Param {
		_X = 100,
		_Y = 100,
		_W = 1000,
		_H = 800,

		_gsX = 800,
		_gsY = 800,
		_gsW = 150,
		_gsH = 50,
	};

	const Font font{ FontMethod::MSDF,48 };


public:
	void Draw() override;
	int32 Run() override;
	void Init() override;
private:
	void WindowInit();
	Rect GameStartBottun;
};

