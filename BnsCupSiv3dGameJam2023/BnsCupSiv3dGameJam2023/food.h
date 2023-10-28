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
	void SetGameClearFoodPoint(int iCount) {
		_ClearFoodPoint = iCount;
	}

	int32 GetNextNeedFoodPoint() {
		return _NextNeedFoodPoint;
	}

	void AddNextFoodPoint(int iCount) {
		_NextNeedFoodPoint += iCount;
	}

	void AddFood(int32 iCount) {
		_Count += iCount;
	}

	void DecFood(int32 iCount) {
		_Count -= iCount;
	}

	void SetFood(int32 iCount) {
		_Count = iCount;
	}

	void SearchFood();



	int32 GetFoodCnt() {
		return _Count;
	}

};

