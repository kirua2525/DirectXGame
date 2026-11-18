#pragma once
#include <KamataEngine.h>

//前方宣言
class Player;

/// <summary>
/// カメラコントローラ
/// </summary>
class CameraController {

public:

	//初期化
	void Initialize();

	//更新
	void Update();
	
	void Reset();

public:

	void SetTarget(Player* target) {

		target_ = target;

	}

	void SetCamera(KamataEngine::Camera* camera) {

		camera_ = camera;

	}

	//矩形
	struct Rect {

		float left = 0.0f;
		float right = 1.0f;
		float bottom = 0.0f;
		float top = 1.0f;

	};

	//void SetMovableArea(Rect area) { movableArea_ = area; }

private:

	KamataEngine::Camera* camera_ = nullptr;

	//カメラ
	float cameraController_ = 0.0f;

	Player* target_ = nullptr;

	//追従対象とカメラの座標の差(オフセット)
	KamataEngine::Vector3 targetOffset_ = {0.0f, 0.0f, -15.0f};
	
	//カメラ移動範囲
	//Rect movableArea_ = {0, 100, 0, 100};

	//カメラの目標座標
	KamataEngine::Vector3 targetPos_;

	//座標補間割合
	static inline const float kInterpolationRate = 0.5f;

	//速度掛け率
	static inline const float kVelocityBias = 0.5f;

	//追従対象の各方向へのカメラ移動補間
	static inline const Rect margin_ = {-100, 100, -50, 50};


};
