#include "ClearScene.h"

using namespace KamataEngine;

void ClearScene::Initialize()
{






}

ClearScene::~ClearScene()
{


}

void ClearScene::Update()
{

	//スペースキーが押されたら終了フラグを立てる
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		clearScened_ = true;
	}





}

void ClearScene::Draw()
{






}
