# include <Siv3D.hpp> // Siv3D v0.6.12

#include "AntNestBoad.h"
#include "Choser.h"


void Main()
{

	int32 WindowSizeH = 600;
	int32 WindowSizeW = 1000;
	//ウィンドウサイズの再設定
	Window::Resize(WindowSizeW, WindowSizeH);

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	AntNestBoad aNest;

	Choser cButton;


	cButton.Init();


	while (System::Update())
	{
		aNest.Draw();
		cButton.NestOpenButton();
		cButton.GetFoodButton();
		cButton.GetWaterButton();
		cButton.BuildButton();
		cButton.ArmyTraning();

		cButton.OnClicked();
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
