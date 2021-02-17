#pragma once
#include "Mesh.h"

class MeshSphere : public Mesh
{
public:
	MeshSphere(Shader* shader, float radius, UINT stackCount = 20, UINT sliceCount = 20);
	~MeshSphere();

private:
	void Create() override;

	float radius;

	UINT stackCount;
	UINT sliceCount;
};
