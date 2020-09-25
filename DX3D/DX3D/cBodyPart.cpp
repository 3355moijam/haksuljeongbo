#include "stdafx.h"
#include "cBodyPart.h"

cBodyPart::cBodyPart(): scale_(1,1,1), pos_(0,0,0), rotate_(0,0,0), direct_(), cube_()
{
}

cBodyPart::~cBodyPart()
{
}

void cBodyPart::setup(D3DXVECTOR3& scale, D3DXVECTOR3& pos)
{
	scale_ = scale;
	pos_ = pos;
}

void cBodyPart::render(D3DXMATRIXA16& matUpperWorld)
{
	D3DXMATRIXA16 matWorld, matScale, matPos, matRotX, matRotY, matRotZ;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, scale_.x, scale_.y, scale_.z);
	D3DXMatrixRotationX(&matRotX, rotate_.x);
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXMatrixRotationZ(&matRotZ, rotate_.z);
	D3DXMatrixTranslation(&matPos, pos_.x, pos_.y, pos_.z);
	matWorld = matScale * matRotX * matRotY * matRotZ * matPos * matUpperWorld;
	cube.render(matWorld);
	/*matScale = matS * matScale;
	matRotX = matX * matRotX;
	matRotY = matY * matRotY;
	matRotZ = matZ * matRotZ;
	matPos = matT * matPos;
	cube_.render(matScale, matRotX, matRotY, matRotZ, matPos);*/

	matWorld = matScale * matRotX * matRotY * matRotZ * matPos* matUpperWorld;


	vector<ST_PC_VERTEX> verIndex;
	verIndex.emplace_back(0, 0, 0, 0xff0000);
	verIndex.emplace_back(3, 0, 0, 0xff0000);
	verIndex.emplace_back(0, 0, 0, 0x00ff00);
	verIndex.emplace_back(0, 3, 0, 0x00ff00);
	verIndex.emplace_back(0, 0, 0, 0x0000ff);
	verIndex.emplace_back(0, 0, 3, 0x0000ff);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_LINELIST,
		verIndex.size() / 2,
		&verIndex[0],
		sizeof ST_PC_VERTEX
	);
}

void cBodyPart::render(D3DXMATRIXA16& matS, D3DXMATRIXA16& matX, D3DXMATRIXA16& matY, D3DXMATRIXA16& matZ,
                       D3DXMATRIXA16& matT)
{
	D3DXMATRIXA16 matWorld, matScale, matPos, matRotX, matRotY, matRotZ;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, scale_.x, scale_.y, scale_.z);
	D3DXMatrixRotationX(&matRotX, rotate_.x);
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXMatrixRotationZ(&matRotZ, rotate_.z);
	D3DXMatrixTranslation(&matPos, pos_.x, pos_.y, pos_.z);
	
	matScale = matS * matScale;
	matRotX = matX * matRotX;
	matRotY = matY * matRotY;
	matRotZ = matZ * matRotZ;
	matPos = matT * matPos;

	matWorld = /*matScale * */matRotX * matRotY * matRotZ * matPos;
	cube_.render(matScale, matRotX, matRotY, matRotZ, matPos);


	vector<ST_PC_VERTEX> verIndex;
	verIndex.emplace_back(0, 0, 0, 0xff0000);
	verIndex.emplace_back(3, 0, 0, 0xff0000);
	verIndex.emplace_back(0, 0, 0, 0x00ff00);
	verIndex.emplace_back(0, 3, 0, 0x00ff00);
	verIndex.emplace_back(0, 0, 0, 0x0000ff);
	verIndex.emplace_back(0, 0, 3, 0x0000ff);
	
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_LINELIST,
		verIndex.size() / 2,
		&verIndex[0],
		sizeof ST_PC_VERTEX
	);
	
}
