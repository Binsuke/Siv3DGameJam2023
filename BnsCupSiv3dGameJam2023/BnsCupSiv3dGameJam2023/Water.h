#pragma once
class Water
{
	int32 _Count;
	int32 _NextNeedFoodPoint;
	int32 _ClearFoodPoint;
	enum Param {
		AddWaterCount = 3,

	};
public:
	void SetNextWaterPoint(int iCount) {
		_NextNeedFoodPoint = iCount;
	}
	void SetClearWaterPoint(int iCount) {
		_ClearFoodPoint = ~iCount;
	}

	void SearchWater();

};

