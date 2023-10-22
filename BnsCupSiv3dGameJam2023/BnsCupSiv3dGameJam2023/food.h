#pragma once
class food
{
private:
	int32 _Count = 0;
	int32 _NextNeedFoodPoint;
	int32 _ClearFoodPoint;
	enum Param {
		AddFoodCount = 3,

	};
public:
	void SetNextFoodPoint(int iCount) {
		_NextNeedFoodPoint = iCount;
	}
	void SetClearFoodPoint(int iCount) {
		_ClearFoodPoint = ~iCount;
	}

	void SearchFood();

	int32 GetFoodCnt() {
		return _Count;
	}

};

