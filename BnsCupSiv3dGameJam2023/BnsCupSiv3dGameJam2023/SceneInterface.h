#pragma once
//#include "Sccene.h"
class SceneInterface
{
public:
	virtual void Init() =0;
	virtual void Draw() =0;
	virtual int32 Run() = 0;
};

