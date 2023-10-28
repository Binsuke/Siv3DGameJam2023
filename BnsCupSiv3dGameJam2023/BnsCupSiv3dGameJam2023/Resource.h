#pragma once
class cResource
{
	int32 _Count=0;
	int32 _ChildCount = 0;
	
public:
	void SearchResource();

	int32 GetResouceCnt() {
		return _Count;
	}

	void UseResource() {
		--_Count;
	}

	void SetResource(int32 iCount) {
		_Count = iCount;
	}

	void DecResource(int32 iCount) {//ここを後で大人と子供の優先順位をつける
		_Count -= iCount;
	}

	int32 GetResourceParentCnt() {
		return _Count;
	}

	int32 GetResourceChildrenCnt() {
		return _ChildCount;
	}
};

