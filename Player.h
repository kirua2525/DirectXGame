#pragma once
#include "KamataEngine.h"
#include <math.h>

/// <summary>
/// 自キャラ
/// </summary>
class Player {

public:

	//初期化
	void Initialaize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	//更新
	void Update();

	//描画
	void Draw();

public:

	const KamataEngine::WorldTransform& GetWorldTransform() const { return worldTransform_; }

	// プレイヤーのワールド座標を直接設定する関数
	void SetWorldPosition(const KamataEngine::Vector3& position);

	// ワールド座標を取得
	KamataEngine::Vector3 GetWorldPosition();




private:

	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;

	// モデル
	KamataEngine::Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	//カメラ
	KamataEngine::Camera* camera_ = nullptr;

	KamataEngine::Vector3 velocity_ = {};





};
