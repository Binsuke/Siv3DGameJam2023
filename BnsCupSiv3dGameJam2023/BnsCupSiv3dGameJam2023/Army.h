#pragma once
class Army
{
private:
	int32 _Count=0;
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
};

