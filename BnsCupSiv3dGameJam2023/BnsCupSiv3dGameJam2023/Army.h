#pragma once
class Army
{
private:
	int32 _Count=0;
	int32 _NeedFood = 2;
	const enum Param {
		TraningCnt = 1,
	};
public:
	void ArmyTraningOnClicked() {
		_Count += Param::TraningCnt;

	}
	int32 GetArmyCnt() {
		return _Count;
	}
	void DecArmy() {
		--_Count;
		if (_Count < 0) {
			_Count = 0;
		}
	}

	void DecArmy(int32 iCount) {
		_Count -= iCount;

		if (_Count < 0) {
			_Count = 0;
		}
	}

	int32 GetAllNeedFood() {
		return (_Count * _NeedFood);
	}
};

