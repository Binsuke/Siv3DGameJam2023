#pragma once
#include "SceneInterface.h"
#include "Title.h"
#include "Choser.h"

class cScene
{
public:
	const enum eSceneParam {
		sTitle = 0,
		sChoser = 1,
		sSceheNum = 2,
		sNoChange = 3,

	};
private:
	
	Title _Title;
	Choser _Choser;

	SceneInterface *_sInterface[cScene::eSceneParam::sSceheNum];
	cScene::eSceneParam NowScene;

	bool InitFlg = false;
public:
	void Init();
	void SceneDraw();
	void SceneInit();
	void SceneRun();
	void SetScene(int32 eSceneNo);
};

