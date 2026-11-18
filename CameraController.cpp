#include "CameraController.h"
#include "Player.h"
#include "3d/WorldTransform.h"
#include <algorithm>
#include <random>

using namespace KamataEngine;

inline float Lerp(float start, float end, float t) {

	return start + (end - start) * t;

}

void CameraController::Initialize()
{
	//カメラの初期化
	cameraController_ = 0.0f;

	target_ = nullptr;
	camera_ = nullptr;

	targetPos_ = {0.0f, 0.0f, 0.0f};

}

void CameraController::Update()
{
	
	if (target_ == nullptr || camera_ == nullptr) {
	
		return;
	
	}

	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();

	//追従対象の速度を取得
	Vector3 targetVelocity = target_->GetVelocity();

	//追従対象の速度を取得
	targetPos_.x = targetWorldTransform.translation_.x + targetOffset_.x + targetVelocity.x * kVelocityBias;
	targetPos_.y = targetWorldTransform.translation_.y + targetOffset_.y + targetVelocity.y * kVelocityBias;
	targetPos_.z = targetWorldTransform.translation_.z + targetOffset_.z + targetVelocity.z * kVelocityBias;

	//座標補間によるゆったり追従
	camera_->translation_.x = Lerp(camera_->translation_.x, targetPos_.x, kInterpolationRate);
	camera_->translation_.y = Lerp(camera_->translation_.y, targetPos_.x, kInterpolationRate);
	camera_->translation_.z = Lerp(camera_->translation_.z, targetPos_.z, kInterpolationRate);
	
	//追従対象が画面外に出ないように補正
	camera_->translation_.x = (std::max)(camera_->translation_.x, targetPos_.x + margin_.left);
	camera_->translation_.x = (std::min)


}

void CameraController::Reset()
{





}