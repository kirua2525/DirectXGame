#include <Windows.h>
#include "GameScene.h"
#include "TitleScene.h"
#include "ClearScene.h"
#include <KamataEngine.h>

using namespace KamataEngine;

//タイトルシーンのインスタンス生成
TitleScene* titleScene = nullptr;
// ゲームシーンのインスタンス生成
GameScene* gameScene = nullptr;
//クリアシーンのインスタンス生成
ClearScene* clearScene = nullptr;

enum class Scene {

	kUnknown = 0,

	kTitle,
	kGame,
	kClear,

};

Scene scene = Scene::kUnknown;

void ChangeScene();
void UpdateScene();
void DrawScene();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	// エンジンの初期化
	Initialize(L"LE2D_23_ナガタ_キルア_AL3");

	// DirectXCommonインスタンスの取得 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	scene = Scene::kTitle;
	titleScene = new TitleScene();
	titleScene->Initialize();

	// ImGuiManagerインスタンスの取得
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();

	//ゲームシーンのインスタンス生成
	gameScene = new GameScene();

	// ゲームシーンの初期化
	gameScene->Initialize();

	// メインループ
	while (true) {

		// エンジンの更新
		if (Update()) {
			break;
		}

		ChangeScene();

		//シーンのアップデート
		UpdateScene();

		// ImGui受付開始
		imguiManager->Begin();

		// ImGui受付終了
		imguiManager->End();

		// 描画処理
		dxCommon->PreDraw();

		DrawScene();

		// 軸表示の描画
		AxisIndicator::GetInstance()->Draw();

		// ImGui描画
		imguiManager->Draw();

		// 描画処理終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの開放
	delete gameScene;
	gameScene = nullptr;

	//タイトルシーン解放
	delete titleScene;
	titleScene = nullptr;

	//クリアシーン解放
	delete clearScene;
	clearScene = nullptr;

	// エンジンの終了処理
	Finalize();

	return 0;
}

void ChangeScene() {

	switch (scene) { 
		case Scene::kTitle:
		if (titleScene && titleScene->IsFinished()) {
			    delete titleScene;
			    titleScene = nullptr;
				
				scene = Scene::kGame;
			    gameScene = new GameScene();
			    gameScene->Initialize();
		}
		break;
			
		case Scene::kGame:
		    
			//ゲームオーバー時
		    if (gameScene->IsFinished()) {
			    delete gameScene;
			    gameScene = nullptr;
				
				scene = Scene::kTitle;
			    titleScene = new TitleScene();
			    titleScene->Initialize();
			}

			//クリア時
		    else if (gameScene->IsClear()) {
			    delete gameScene;
			    gameScene = nullptr;
				
				scene = Scene::kClear;
			    clearScene = new ClearScene();
			    clearScene->Initialize();

			
			}
		    break;

		case Scene::kClear:
		    if (clearScene && clearScene->IsClear()) {
			    delete clearScene;
			    clearScene = nullptr;
				
				scene = Scene::kClear;
			    titleScene = new TitleScene();
			    titleScene->Initialize();
			
			}
		    break;
	}
}

void UpdateScene()
{

	switch (scene)
	{ 
		case Scene::kTitle:
		titleScene->Update();
		    break;

		case Scene::kGame:
		    gameScene->Update();

		case Scene::kClear:
		    clearScene->Update();
		    break;

	}
}

void DrawScene()
{

	switch (scene) {

		case Scene::kTitle:
		titleScene->Draw();
		    break;

		case Scene::kGame:
		    gameScene->Draw();
		    break;

		case Scene::kClear:
		    clearScene->Draw();
		    break;

	}
}