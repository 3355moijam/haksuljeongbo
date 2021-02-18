#pragma once
#include "Systems/IExecute.h"
#include <array>

class DrawTexture : public IExecute
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
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;

	//ID3D11ShaderResourceView* srv;
	Texture* texture;
};

