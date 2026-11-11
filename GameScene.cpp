#include "GameScene.h"
#include "2d/ImGuiManager.h"
#include <algorithm>

using namespace KamataEngine;

void GameScene::Initialize() {


	// 3Dモデルの生成
	modelSkydome_ = Model::CreateFromOBJ("skydome", true);

	
	//スカイドームの生成
	skydome_ = new Skydome(); 
	skydome_->Initialize(modelSkydome_, &camera_);


}

void GameScene::Update() {

	//天球の更新処理
	skydome_->Update();




}

void GameScene::Draw() {

	//天球の描画
	skydome_->Draw();





}

GameScene::~GameScene() {






	delete skydome_;

}