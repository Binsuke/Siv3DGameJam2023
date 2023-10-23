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
		 Pos_TopLeft_Y = 250,//170,

		 InitPosx = 4,
		 InitPosY = 0,

	};

	const enum eNestData {
		Close = 0,
		Open = 1,
		canOpen = 2,
		Build = 3,

		Color_Pattern = 6,
		cpClose = 0,
		cpOpen = 1,
		cpCanOpen = 0,		//cpCloseと見た目は同じ
		cpMouseOver = 2,
		cpMouseOverCant = 3,
		cpBuildMouseOver = 4,
		cpBuild = 5,
	};
	//のちのちテクスチャーに変更するかも
	


	//const int32 NestSizeW = 9;
	//const int32 NestSizeH = 80;
	const enum NestSize {
		_W = 9,
		_H = 7,
	};
	Color iColorPicker[eNestData::Color_Pattern];
	Color fColorPicker[eNestData::Color_Pattern];

	Color iColor[NestSize::_W][NestSize::_H];
	Color fColor[NestSize::_W][NestSize::_H];

	int32 NestData[NestSize::_W][NestSize::_H];

	Rect NestRect[NestSize::_W][NestSize::_H];

	bool InitFlg = false;

	int32 HouseCnt = 0;


	bool isValid(int32 x,int32 y);

	void InitCanOpenSet(int x, int y);

	
	//const Texture texture{U}
public:
	void Draw();
	bool OnClicked(int x,int y);
	bool MouseOveredChangeColor(bool OpenFlg);

	bool BuildOnClicked(int x, int y);
	bool BuildMouseOveredChangeColor(bool OpenFlg);

	void BoadClear();
	void BoadUpdate(int32 x,int32 y);

	void BoadOpen(int x, int y);

	int32 GetHouseCnt() {
		return HouseCnt;
	}

	//void SearchCanOpenBlock();
	//void CheckBlockState( int32 x, int32 y);
};

