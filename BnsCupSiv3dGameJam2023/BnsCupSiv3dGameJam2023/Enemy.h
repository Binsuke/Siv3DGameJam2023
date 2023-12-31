﻿#pragma once
class Enemy
{
private:
	int32 _Count = 0;
	int32 _NeedFood = 2;

public:
	void SetNextEnemyCount(int32 iCount) {
		_Count = iCount;
	}
	int32 GetCount() {
		return _Count;
	}
	int32 GetAllNeedFood() {
		return (_Count * _NeedFood);
	}
	void AddEnemy(int32 iCount) {
		_Count += iCount;
	}

};

