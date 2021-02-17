#pragma once
#include "Mesh.h"
class MeshCylinder: public Mesh
{
public:
	MeshCylinder(Shader* shader, float radius, float height, UINT sliceCount = 10, UINT stackCount = 10);
	~MeshCylinder();

private:
	void Create() override;

	void BuildTopCap(vector<MeshVertex>& vertices, vector<UINT>& indices);
	void BuildBottomCap(vector<MeshVertex>& vertices, vector<UINT>& indices);

	float topRadius;
	float bottomRadius;
	float height;

	UINT sliceCount;
	UINT stackCount;
};
