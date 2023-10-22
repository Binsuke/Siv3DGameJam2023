#pragma once
class AntNestBoad
{
public:
	AntNestBoad() {
		for (int x = 0; x < NestSize::_W; x++) {
			for (int y = 0; y < NestSize::_H; y++) {
				if (x == 4 && y == 0) {
					NestData[x][y] = NestData::Open;
				}
				else {
					NestData[x][y] = NestData::Close;
				}
			}
		}
	}
	void Init();
private:
	const enum Param{
		 SizeH = 90,
		 SizeW = 90,
		 Pos_TopLeft_X = 70,
		 Pos_TopLeft_Y = 170,

		 
	};

	const enum NestData {
		Close = 0,
		Open = 1,

		Color_Pattern = 3,
		cpClose = 0,
		cpOpen = 1,
		cpMouseOver = 2,
	};
	//のちのちテクスチャーに変更するかも
	


	//const int32 NestSizeW = 9;
	//const int32 NestSizeH = 80;
	const enum NestSize {
		_W = 9,
		_H = 6,
	};
	Color iColorPicker[NestData::Color_Pattern];
	Color fColorPicker[NestData::Color_Pattern];

	Color iColor[NestSize::_W][NestSize::_H];
	Color fColor[NestSize::_W][NestSize::_H];

	int32 NestData[NestSize::_W][NestSize::_H];

	Rect NestRect[NestSize::_W][NestSize::_H];

	bool InitFlg = false;

	//const Texture texture{U}
public:
	void Draw();
	void OnClicked();
	void MousuOverChangeColor();

};

