#define NOMINMAX
#include "Player.h"
#include <algorithm>
#include <cassert>
#include <numbers>

using namespace KamataEngine;

void Player::Initialaize(KamataEngine::Model* model, KamataEngine::Camera* camera, const Vector3& position) {

	//NULLポインタチェック
	assert(model);

	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;

	// 引数の内容をメンバ変数に記録
	camera_ = camera;

}

void Player::Update() {







}

void Player::Draw() {

	// 3Dモデル描画前処理
	Model::PreDraw();

	// 3Dモデルを描画
	model_->Draw(worldTransform_, *camera_);

	// 3Dモデル描画を処理
	Model::PostDraw();

}
