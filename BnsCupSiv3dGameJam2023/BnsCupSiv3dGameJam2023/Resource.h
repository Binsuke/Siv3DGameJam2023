#pragma once
class ResourceData {
private:
	int32 Age = 0;
	int32 NeedFood = 1;
public:
	int32 GetAge() {
		return Age;
	}
	int32 GetNeedFood() {
		return NeedFood;
	}
	void AgeUpdate() {
		++Age;
		if (Age >= 4) {
			NeedFood = 2;//４週間たったら必要食料を増やす
		}
	}
};


class cResource
{
	int32 _Count=0;
	int32 _ChildCount = 0;
	int32 _ReserchCnt = 0;
private:
	Array<ResourceData> rDataArray;
	
public:
	void SearchResource();

	int32 GetResouceCnt() {
		return _Count;
	}

	void UseResource() {
		rDataArray.pop_front_N(1);
		--_Count;
		--_ReserchCnt;
	}

	int32 GetNeedFood();

	void AddResorce() {
		++_Count;
	}

	void AddResorce(int32 iCount) {
		for (int i = 0; i < iCount; i++) {
			++_Count;
		}
	}
	void DecResource(int32 iCount) {//ここを後で大人と子供の優先順位をつける
		rDataArray.pop_front_N(iCount);//先頭からアリのリソースを失う
		for (int i = 0; i < iCount; i++) {
			--_Count;
		}
	}

	int32 GetResourceParentCnt() {//大人のアリの数だけ返す
		int32 tmp = 0;
		for (int i = 0; i < rDataArray.size(); i++) {
			if (rDataArray[i].GetAge() >= 4) {
				++tmp;
			}
		}
		return tmp;
	}

	int32 GetResourceChildrenCnt() {//子供のアリのみリターン
		int32 tmp = 0;
		for (int32 i = 0; i < rDataArray.size(); i++) {
			if (rDataArray[i].GetAge() < 4) {
				++tmp;
			}
		}
		return tmp;
	}

	int32 GetEnoughFood(int32 iFoodCnt);

	void WeekEndResourceAgeUpdate();

	void UpdateReserchCnt();

	int32 GetReserchCnt();

	void UseReserch() {
		--_ReserchCnt;
	}
};

