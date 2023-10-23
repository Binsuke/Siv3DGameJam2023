#pragma once
class Enemy
{
private:
	int32 _Count = 0;

public:
	void SetNextEnemyCount(int32 iCount) {
		_Count = iCount;
	}
	int32 GetCount() {
		return _Count;
	}
};

