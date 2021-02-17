#include "Framework.h" 
#include "Mesh.h"

Mesh::Mesh(Shader* shader)
	: shader(shader)  
	, position(0,0,0) , scale(1,1,1) , rotation(0,0,0) 
	, vertexBuffer(NULL) , indexBuffer(NULL) 
	, pass(0) , color(0,0,0,1)
{
	D3DXMatrixIdentity(&world); 
	sWorld = shader->AsMatrix("World"); 
	sView = shader->AsMatrix("View"); 
	sProjectdion = shader->AsMatrix("Projection"); 
	sColor = shader->AsVector("Color"); 
}


Mesh::~Mesh()
{
	SafeDeleteArray(vertices);
	SafeDeleteArray(indices); 

	SafeRelease(vertexBuffer); 
	SafeRelease(indexBuffer); 
}

void Mesh::Render()
{
	if (vertexBuffer == NULL && indexBuffer == NULL)
	{
		Create(); 
		CreateBuffer(); 
	}

	UINT stride = sizeof(MeshVertex); 
	UINT offset = 0; 

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer,
		&stride, &offset); 
	D3D::GetDC()->IASetIndexBuffer(indexBuffer,
		DXGI_FORMAT_R32_UINT, 0); 
	D3D::GetDC()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST); 
	
	sWorld->SetMatrix(world); 
	sView->SetMatrix(Context::Get()->View()); 
	sProjectdion->SetMatrix(Context::Get()->Projection()); 
	sColor->SetFloatVector(color); 

	shader->DrawIndexed(0, pass, indexCount); 
}

void Mesh::Position(float x, float y, float z)
{
	position = D3DXVECTOR3(x, y, z);
	UpdateWorld();
}

void Mesh::Position(D3DXVECTOR3 & vec)
{
	position = vec; 
	UpdateWorld(); 
}

void Mesh::Position(D3DXVECTOR3 * vec)
{
	*vec = position; 
}

void Mesh::Rotation(float x, float y, float z)
{
	rotation = D3DXVECTOR3(x, y, z);
	UpdateWorld();
}

void Mesh::Rotation(D3DXVECTOR3 & vec)
{
	rotation = vec; 
	UpdateWorld(); 
}

void Mesh::Rotation(D3DXVECTOR3 * vec)
{
	*vec = rotation; 
}

void Mesh::RotationDegree(float x, float y, float z)
{
	rotation = D3DXVECTOR3(x, y, z) * Math::PI / 180.0f;
	UpdateWorld();
}

void Mesh::RotationDegree(D3DXVECTOR3 & vec)
{
	rotation = vec * Math::PI / 180.0f ;
	UpdateWorld();
}

void Mesh::RotationDegree(D3DXVECTOR3 * vec)
{
	*vec = rotation * 180.0f  / Math::PI ;
}

void Mesh::Scale(float x, float y, float z)
{
	scale = D3DXVECTOR3(x, y, z);
	UpdateWorld();
}

void Mesh::Scale(D3DXVECTOR3 & vec)
{
	scale = vec; 
	UpdateWorld(); 
}

void Mesh::Scale(D3DXVECTOR3 * vec)
{
	*vec = scale; 
}

void Mesh::Matrix(D3DXMATRIX * mat)
{
	memcpy(mat, &world, sizeof(D3DXMATRIX)); 
}

void Mesh::Color(D3DXCOLOR & val)
{
	color = val; 
}

void Mesh::Color(float r, float g, float b)
{
	color = D3DXCOLOR(r, g, b, 1.0f);
}

void Mesh::CreateBuffer()
{
	// : create vertex buffer 
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(MeshVertex) * vertexCount;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA data = { 0 };
		data.pSysMem = vertices;

		Check(D3D::GetDevice()->CreateBuffer(&desc,
			&data,
			&vertexBuffer));
	}

	// : create index buffer 
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(UINT) * indexCount;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		D3D11_SUBRESOURCE_DATA data = { 0 };
		data.pSysMem = indices;
		Check(D3D::GetDevice()->CreateBuffer(&desc,
			&data,
			&indexBuffer));
	}
}

void Mesh::UpdateWorld()
{
	D3DXMATRIX S, R, T; 
	D3DXMatrixScaling(&S, scale.x, scale.y, scale.z); 
	D3DXMatrixRotationYawPitchRoll(&R , 
		rotation.y, rotation.x, rotation.z); 
	D3DXMatrixTranslation(&T, position.x, position.y, position.z); 

	world = S*R*T; 
}
