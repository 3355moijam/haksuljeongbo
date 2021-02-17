#pragma once
#include "Systems/IExecute.h"
#include <array>

class DrawVertex : public IExecute
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
	Shader* shader;
	UINT width = 256;
	UINT height = 256;

	UINT vertexCount;
	vector<Vertex> vertices;
	ID3D11Buffer* vertexBuffer;

	UINT indexCount;
	vector<UINT> indices;
	ID3D11Buffer* indexBuffer;

	Color color;
	//UINT number;
	
};

