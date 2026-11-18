#pragma once
#include "KamataEngine.h"
#include <numbers>

class TitleScene {

public:

	void Initialize();

	void Update();

	void Draw();

	~TitleScene();

public:

	bool IsFinished() const { return finished_; }

private:

	//終了フラグ
	bool finished_ = false;


};
