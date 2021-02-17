#pragma once

class FreeCam : public Camera
{
public:
	FreeCam();
	~FreeCam();

	void Update();
	void Speed(float move, float rotation);

private:
	float move;
	float rotation;
};
