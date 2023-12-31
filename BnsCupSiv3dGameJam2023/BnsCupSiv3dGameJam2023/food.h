﻿#pragma once
class food
{
private:
	enum Param {
		StartFood = 4,
		AddFoodCount = 2,
	};
	int32 _Count = food::Param::StartFood;
	int32 _NextNeedFoodPoint;
	int32 _ClearFoodPoint;
	
public:

	void Init() {
		_Count = food::Param::StartFood;
	}
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

	int32 GetAddFoodCnt() {
		return food::Param::AddFoodCount;
	}

	int32 GetFoodCnt() {
		return _Count;
	}

};

