#include <Windows.h>
#include "GameScene.h"
#include <KamataEngine.h>

using namespace KamataEngine;

// ゲームシーンのインスタンス生成
GameScene* gameScene = nullptr;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	// エンジンの初期化
	Initialize(L"LE2D_23_ナガタ_キルア_AL3");

	// DirectXCommonインスタンスの取得 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

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

		// ImGui受付開始
		imguiManager->Begin();

		// ImGui受付終了
		imguiManager->End();

		// 描画処理
		dxCommon->PreDraw();

		// 軸表示の描画
		AxisIndicator::GetInstance()->Draw();

		// ImGui描画
		imguiManager->Draw();

		// 描画処理終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの開放
	delete gameScene;
	
	// nullptrの代入
	gameScene = nullptr;






	// エンジンの終了処理
	Finalize();

	return 0;
}
