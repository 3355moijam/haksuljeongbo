#pragma once
#include "cLight.h"

class cDirectionalLight : public cLight
{
public:
	~cDirectionalLight() override;
	void setup() override;
	void update() override;
	void render() override;
};
