#include <KamataEngine.h>
#include <vector>
#include "Skydome.h"


#pragma once
class GameScene {
public:

	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

	~GameScene();

private:

	KamataEngine::WorldTransform worldTransform_;

	//スカイドーム
	Skydome* skydome_ = nullptr;

	//3Dモデル
	KamataEngine::Model* modelSkydome_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	// デバッグカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;


};
