#include "GameScene.h"
#include "2d/ImGuiManager.h"
#include <algorithm>

using namespace KamataEngine;

void GameScene::Initialize() {

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("player/player.png");

	// 3Dモデルの生成
	model_ = Model::CreateFromOBJ("player");
	modelSkydome_ = Model::CreateFromOBJ("skydome", true);

	//自キャラの生成
	player_ = new Player();


	//スカイドームの生成
	skydome_ = new Skydome(); 
	skydome_->Initialize(modelSkydome_, &camera_);


	//プレイヤー座標
	Vector3 playerPosition = (100, 100, 100);

	//自キャラの初期化
	player_->Initialaize(model_, &camera_, playerPosition);







}

void GameScene::Update() {

	//天球の更新処理
	skydome_->Update();

	//自キャラの更新
	player_->Update();

	//デバッグカメラの更新
	debugCamera_->Update();

		// カメラの処理
	if (isDebugCameraActive_) {
		// デバッグカメラの更新
		camera_.matView = debugCamera_->GetCamera().matView;
		camera_.matProjection = debugCamera_->GetCamera().matProjection;

		// ビュープロジェクション行列の転送
		camera_.TransferMatrix();
	} else {

		//cameraController_->Update();

		// ビュープロジェクション行列の更新と転送
		camera_.UpdateMatrix();
	}


}

void GameScene::Draw() {

	//自キャラの描画
	player_->Draw();

	//天球の描画
	skydome_->Draw();

	Model::PreDraw();

	Model::PostDraw();

}

GameScene::~GameScene() {


	delete model_;
	delete player_;

	delete debugCamera_;

	delete modelSkydome_;
	delete skydome_;

}