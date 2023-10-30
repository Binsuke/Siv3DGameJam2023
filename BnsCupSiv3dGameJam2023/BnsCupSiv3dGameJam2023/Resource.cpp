#include "stdafx.h"
#include "Resource.h"


void cResource::SearchResource() {
	++_Count;
	ResourceData tmpdata;
	rDataArray << tmpdata;
}

int32 cResource::GetNeedFood() {
	int32 tmp = 0;
	for (int i = 0; i < rDataArray.size(); i++) {
		tmp += rDataArray[i].GetNeedFood();
	}
	return tmp;
}

int32 cResource::GetEnoughFood(int32 iFoodCnt) {
	int32 tmp = -1;
	int32 ReturnEnoughFood = 0;
	//int32 EnoughFood = iEnoughFood - iFoodCnt;
	for (int32 i = ((rDataArray.size()) - 1); i >= 0; i--) {//データの後ろ側から参照
		if (iFoodCnt - rDataArray[i].GetNeedFood() >= 0) {//現在の食料の数からデータ内の必要な数を引いて食料が０以上なら
			iFoodCnt -= rDataArray[i].GetNeedFood();
		}
		else {//食料の数が足りないなら
			tmp = i;//その時の番号を保存してfor分からbreak
			break;
		}
	}
	for (int32 i = 0; i <= tmp; i++) {//前から参照して、残りの足りない食料の数をリターン
		ReturnEnoughFood += rDataArray[i].GetNeedFood(); //必要な食料の数を足しこむ
	}
	return ReturnEnoughFood;
}

