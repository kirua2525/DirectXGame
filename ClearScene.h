#pragma once
#include "KamataEngine.h"
#include <numbers>

class ClearScene {

public:

	void Initialize();

	void Update();

	void Draw();

	~ClearScene();

public:

	bool IsClear() const { return clearScened_; }


private:

	bool clearScened_ = false;


};
