#pragma once
class AntNestBoad
{
public:
	AntNestBoad() {
		BoadClear();
	}
	void Init();
private:
	const enum Param{
		 SizeH = 90,
		 SizeW = 90,
		 Pos_TopLeft_X = 70,
		 Pos_TopLeft_Y = 170,

		 InitPosx = 4,
		 InitPosY = 0,

	};

	const enum eNestData {
		Close = 0,
		Open = 1,
		canOpen = 2,

		Color_Pattern = 4,
		cpClose = 0,
		cpOpen = 1,
		cpCanOpen = 0,
		cpMouseOver = 2,
		cpMouseOverCant = 3,
	};
	//のちのちテクスチャーに変更するかも
	


	//const int32 NestSizeW = 9;
	//const int32 NestSizeH = 80;
	const enum NestSize {
		_W = 9,
		_H = 6,
	};
	Color iColorPicker[eNestData::Color_Pattern];
	Color fColorPicker[eNestData::Color_Pattern];

	Color iColor[NestSize::_W][NestSize::_H];
	Color fColor[NestSize::_W][NestSize::_H];

	int32 NestData[NestSize::_W][NestSize::_H];

	Rect NestRect[NestSize::_W][NestSize::_H];

	bool InitFlg = false;

	bool isValid(int32 x,int32 y);

	void InitCanOpenSet(int x, int y);

	
	//const Texture texture{U}
public:
	void Draw();
	void OnClicked();
	void MouseOveredChangeColor(bool OpenFlg);

	void BoadClear();
	void BoadUpdate(int32 x,int32 y);

	void BoadOpen(int x, int y);

	//void SearchCanOpenBlock();
	//void CheckBlockState( int32 x, int32 y);
};

