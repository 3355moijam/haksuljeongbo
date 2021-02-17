#include "stdafx.h"
#include "DrawTexture.h"

void DrawTexture::Initialize()
{
	Context::Get()->GetCamera()->Position(0, 0, -3);
	
	shader = new Shader(L"005_Texture.fx");
	{
		vector<VertexTexture> vertices(4);
		vertices[0].Position = Vector3(-0.5f, -0.5f, 0.0f);
		vertices[1].Position = Vector3(-0.5f,  0.5f, 0.0f);
		vertices[2].Position = Vector3( 0.5f, -0.5f, 0.0f);
		vertices[3].Position = Vector3( 0.5f,  0.5f, 0.0f);

		vertices[0].Uv = Vector2(0, 1);
		vertices[1].Uv = Vector2(0, 0);
		vertices[2].Uv = Vector2(1, 1);
		vertices[3].Uv = Vector2(1, 0);
		
		D3D11_BUFFER_DESC desc{};
		//ZeroMemory(&desc, sizeof D3D11_BUFFER_DESC);
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof VertexTexture * vertices.size();
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource{};
		subResource.pSysMem = &vertices[0];
	
		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer));
	}
	{
		// >> index buffer
		vector<UINT> indices{ 0,1,2,2,1,3 };
		D3D11_BUFFER_DESC desc_index{};
		ZeroMemory(&desc_index, sizeof D3D11_BUFFER_DESC);
		desc_index.Usage = D3D11_USAGE_DEFAULT;
		desc_index.ByteWidth = sizeof UINT * indices.size();
		desc_index.BindFlags = D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource_index{};
		subResource_index.pSysMem = &indices[0];

		Check(D3D::GetDevice()->CreateBuffer(&desc_index, &subResource_index, &indexBuffer));
		// <<
	}
	{
		// >> texture
		//D3DX11CreateShaderResourceViewFromFile
		//(
		//	D3D::GetDevice(), L"../../_Textures/Box.png", NULL, NULL, &srv, NULL
		//);
		texture = new Texture(L"Box.png");

		shader->AsSRV("Map")->SetResource(texture->SRV());
		// <<
	}
	
}

void DrawTexture::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
	SafeRelease(indexBuffer);
}

void DrawTexture::Update()
{
	Matrix world;
	D3DXMatrixScaling(&world, 1, 1, 1);
	shader->AsMatrix("World")->SetMatrix(world);

	Matrix view = Context::Get()->View();
	shader->AsMatrix("View")->SetMatrix(view);

	Matrix projection = Context::Get()->Projection();
	shader->AsMatrix("Projection")->SetMatrix(projection);

}

void DrawTexture::Render()
{
	UINT stride = sizeof Vertex;
	UINT offset = 0;
	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	D3D::GetDC()->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//static bool b = true;
	//ImGui::Checkbox("Wireframe", &b);
	shader->DrawIndexed(0, 0 , 6);
		
	//// rect 2
	//{
	//	static Vector3 position(-1, 0, 0);
	//	Matrix world;
	//	D3DXMatrixTranslation(&world, position);
	//	Color color(1, 1, 1, 1);
	//	shader->AsVector("Color")->SetFloatVector(color);
	//	shader->AsMatrix("World")->SetMatrix(world);
	//	shader->Draw(0, 0, vertices.size());
	//}
	//shader->Draw(0, 0, vertices.size());
}
