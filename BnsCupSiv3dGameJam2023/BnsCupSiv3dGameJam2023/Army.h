﻿#pragma once
class Army
{
private:
	int32 _Count;
	const enum Param {
		TraningCnt = 1,
	};
public:
	void ArmyTraningOnClicked() {
		_Count = Param::TraningCnt;
	}
};
