#include "Skydome.h"

using namespace KamataEngine;

Skydome::~Skydome() {  }

//Initiakizeの関数の定義
void Skydome::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera) {

	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	//引数の内容をメンバ変数に記録
	camera_ = camera;

	//ワールド変換の初期化
	worldTransform_.Initialize();

}

//Updateの関数の定義
void Skydome::Update() {}

//Drawの関数の定義
void Skydome::Draw() {

	Model::PreDraw();

	model_->Draw(worldTransform_, *camera_);

	Model::PostDraw();

}