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
