#pragma once
class DrawWindow
{
private:
	Rect _RectWindow;
	Rect _RectOKWindow;
	int32 _X = 0,_Y = 0, _W = 0, _H = 0;
	int32 _OKX=0, _OKY=0, _OKW=0,_OKH=0;
	Color _WindowInColor=ColorF(1), _WindowOutColor=ColorF(0);
	Color _OKWindowInColor = ColorF(0.5), _OKWindowOutColor=ColorF(0.3);
	const Font font{ FontMethod::MSDF,48 };
	bool DrawFlg = false;
public:
	void InitWindow(int32 iX,int32 iY,int32 iW, int32 iH,int32 iOKX,int32 iOKY,int32 iOKW,int32 iOKH);

	void InitWindow(int32 iX, int32 iY, int32 iW, int32 iH);

	void SetColor(Color iWindowInColor, Color iWindowOutColor, Color iOKWindowInColor, Color iOKWindowOutColor) {
		_WindowInColor = iWindowInColor;
		_WindowOutColor = iWindowOutColor;
		_OKWindowInColor = iOKWindowInColor;
		_OKWindowOutColor = iOKWindowOutColor;
	}

	void SetColor(Color iWindowInColor, Color iWindowOutColor) {
		_WindowInColor = iWindowInColor;
		_WindowOutColor = iWindowOutColor;
	}

	bool OnClicked();

	void Draw( String str);

	void DrawWindowOnly(String str);

	void DrawWindowOnly(String str, int32 StrSize);

	void DrawWindowOnly(String str, int32 StrSize, int32 offsetX, int32 offsetY);
};

