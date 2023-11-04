#include "stdafx.h"
#include "Sccene.h"


void cScene::Init() {

	_sInterface[cScene::eSceneParam::sTitle] = &_Title;
	_sInterface[cScene::eSceneParam::sChoser] = &_Choser;

	NowScene = cScene::eSceneParam::sTitle;
}


void cScene::SceneInit() {
	if (!InitFlg) {
		_sInterface[NowScene]->Init();
		InitFlg = true;
	}
}


void cScene::SceneDraw() {
	_sInterface[NowScene]->Draw();
}

void cScene::SceneRun() {
	SetScene(_sInterface[NowScene]->Run());
	//_sInterface[NowScene]->Run();
}

void cScene::SetScene(int32 eSceneNo) {
	switch (eSceneNo) {
	case cScene::eSceneParam::sNoChange:
		break;
	case cScene::eSceneParam::sTitle:
		NowScene = cScene::eSceneParam::sTitle;
		InitFlg = false;
		break;
	case cScene::eSceneParam::sChoser:
		NowScene = cScene::eSceneParam::sChoser;
		InitFlg = false;
		break;
	}
}
