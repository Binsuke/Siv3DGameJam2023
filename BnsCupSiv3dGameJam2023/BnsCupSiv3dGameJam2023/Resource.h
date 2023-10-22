#pragma once
class cResource
{
	int32 _Count=0;
	enum Param {
		AddWaterCount = 3,

	};
public:
	void SearchResource();

	int32 GetResouceCnt() {
		return _Count;
	}

	void UseResource() {
		--_Count;
	}
};

