#pragma once
#include "Systems/IExecute.h"
#include <array>

class Export : public IExecute
{
public:
	void Initialize() override;
	void Ready() override {}
	void Destroy() override;
	void Update() override;
	void PreRender() override {}
	void Render() override;
	void PostRender() override {}
	void ResizeScreen() override {}

private:
	void Tank();
	void Tower();
	void Eclipse();
	void Kachujin();
};

