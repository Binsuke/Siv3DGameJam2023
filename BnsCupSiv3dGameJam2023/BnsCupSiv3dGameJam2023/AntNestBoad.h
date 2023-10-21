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
					NestData[x][y] = NestData::Block;
				}
			}
		}
	}
private:
	const enum Param{
		 SizeH = 90,
		 SizeW = 90,
		 Pos_TopLeft_X = 50,
		 Pos_TopLeft_Y = 200,
	};

	const enum NestData {
		Open = 0,
		Block = 1,
	};

	//const int32 NestSizeW = 9;
	//const int32 NestSizeH = 80;
	const enum NestSize {
		_W = 9,
		_H = 4,
	};
	int32 NestData[NestSize::_W][NestSize::_H];
	//const Texture texture{U}
public:
	void Draw();
};

