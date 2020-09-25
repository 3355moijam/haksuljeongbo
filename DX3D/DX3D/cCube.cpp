#include "stdafx.h"
#include "cCube.h"




cCube::cCube()
	:vertex(),
	speed(0.2f), direct_(0, 0, 1),
	scale_(1, 1, 1), pos_(0,0,0), rotate_(0,0,0)
{
	//vertex.push_back(ST_PC_VERTEX(-1	, -1, -1, D3DCOLOR_XRGB(255, 0, 0 )));
	//vertex.push_back(ST_PC_VERTEX(-1	, 1	, -1, D3DCOLOR_XRGB(0, 255, 0 )));
	//vertex.push_back(ST_PC_VERTEX(1	, 1	, -1, D3DCOLOR_XRGB(0, 0, 255)));
	//vertex.push_back(ST_PC_VERTEX(1	, -1, -1, D3DCOLOR_XRGB(255, 0, 0 )));

	vertex.emplace_back(-1	, -1, -1, D3DCOLOR_XRGB(255, 0, 0));
	vertex.emplace_back(-1	, 1	, -1, D3DCOLOR_XRGB(0, 255, 0));
	vertex.emplace_back(1	, 1	, -1, D3DCOLOR_XRGB(0, 0, 255));
	vertex.emplace_back(1	, -1, -1, D3DCOLOR_XRGB(255, 0, 0));


	//
	vertex.emplace_back(-1	, -1, 1, D3DCOLOR_XRGB(0, 0, 255 )	);
	vertex.emplace_back(-1	, 1	, 1, D3DCOLOR_XRGB(0, 0, 255 )	);
	vertex.emplace_back(1	, 1	, 1, D3DCOLOR_XRGB(0, 0, 255 )	);
	vertex.emplace_back(1	, -1, 1, D3DCOLOR_XRGB(0, 0, 255 )	);

	// 폴리곤 만들기
	{
		//front
		verIndex.push_back(vertex[0]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 0, 255);
		verIndex.push_back(vertex[1]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 0, 255);
		verIndex.push_back(vertex[2]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 0, 255);
								   
		verIndex.push_back(vertex[0]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 0, 255);
		verIndex.push_back(vertex[2]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 0, 255);
		verIndex.push_back(vertex[3]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 0, 255);
		//back					   
		verIndex.push_back(vertex[4]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 255);
		verIndex.push_back(vertex[6]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 255);
		verIndex.push_back(vertex[5]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 255);

		verIndex.push_back(vertex[4]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 255);
		verIndex.push_back(vertex[7]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 255);
		verIndex.push_back(vertex[6]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 255);
								   
		//left					   
		verIndex.push_back(vertex[4]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 0);
		verIndex.push_back(vertex[5]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 0);
		verIndex.push_back(vertex[1]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 0);
								   
		verIndex.push_back(vertex[4]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 0);
		verIndex.push_back(vertex[1]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 0);
		verIndex.push_back(vertex[0]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 0);
								   
		//right					   
		verIndex.push_back(vertex[3]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 255, 0);
		verIndex.push_back(vertex[2]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 255, 0);
		verIndex.push_back(vertex[6]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 255, 0);
								   
		verIndex.push_back(vertex[3]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 255, 0);
		verIndex.push_back(vertex[6]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 255, 0);
		verIndex.push_back(vertex[7]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 255, 0);
								   
		//up					   
		verIndex.push_back(vertex[1]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 255);
		verIndex.push_back(vertex[5]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 255);
		verIndex.push_back(vertex[6]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 255);
								   
		verIndex.push_back(vertex[1]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 255);
		verIndex.push_back(vertex[6]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 255);
		verIndex.push_back(vertex[2]);
		verIndex.back().c = D3DCOLOR_XRGB(255, 0, 255);
								   
		//down					   
		verIndex.push_back(vertex[4]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 0);
		verIndex.push_back(vertex[0]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 0);
		verIndex.push_back(vertex[3]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 0);
								   
		verIndex.push_back(vertex[4]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 0);
		verIndex.push_back(vertex[3]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 0);
		verIndex.push_back(vertex[7]);
		verIndex.back().c = D3DCOLOR_XRGB(0, 255, 0);

		////front
		//verIndex.push_back(0);
		//verIndex.push_back(1);
		//verIndex.push_back(2);
		//					
		//verIndex.push_back(0);
		//verIndex.push_back(2);
		//verIndex.push_back(3);
		////back				
		//verIndex.push_back(4);
		//verIndex.push_back(6);
		//verIndex.push_back(5);
		//					
		//verIndex.push_back(4);
		//verIndex.push_back(7);
		//verIndex.push_back(6);
		//					
		////left				
		//verIndex.push_back(4);
		//verIndex.push_back(5);
		//verIndex.push_back(1);
		//					
		//verIndex.push_back(4);
		//verIndex.push_back(1);
		//verIndex.push_back(0);
		//					
		////right				
		//verIndex.push_back(3);
		//verIndex.push_back(2);
		//verIndex.push_back(6);
		//					
		//verIndex.push_back(3);
		//verIndex.push_back(6);
		//verIndex.push_back(7);
		//					
		////up				
		//verIndex.push_back(1);
		//verIndex.push_back(5);
		//verIndex.push_back(6);
		//					
		//verIndex.push_back(1);
		//verIndex.push_back(6);
		//verIndex.push_back(2);
		//					
		////down				
		//verIndex.push_back(4);
		//verIndex.push_back(0);
		//verIndex.push_back(3);
		//					
		//verIndex.push_back(4);
		//verIndex.push_back(3);
		//verIndex.push_back(7);
	}

}



extern RECT g_view;
void DrawCircle(HDC hdc, int x, int y, int r = 5)
{
	Ellipse(hdc, x - r, y - r, x + r, y + r);
}
void cCube::render()
{
	D3DXMATRIXA16 matWorld, matScale, matPos, matRotX, matRotY, matRotZ;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, scale_.x, scale_.y, scale_.z);
	D3DXMatrixRotationX(&matRotX, rotate_.x);
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXMatrixRotationZ(&matRotZ, rotate_.z);
	D3DXMatrixTranslation(&matPos, pos_.x, pos_.y, pos_.z);
	matWorld = matScale * matRotX * matRotY * matRotZ * matPos;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP
	(	
		D3DPT_TRIANGLELIST,
		verIndex.size() / 3 ,
			&verIndex[0],
			sizeof ST_PC_VERTEX
	);
}

void cCube::render(D3DXMATRIXA16& matUpperWorld)
{
	D3DXMATRIXA16 matWorld, matScale, matPos, matRotX, matRotY, matRotZ;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, scale_.x, scale_.y, scale_.z);
	D3DXMatrixRotationX(&matRotX, rotate_.x);
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXMatrixRotationZ(&matRotZ, rotate_.z);
	D3DXMatrixTranslation(&matPos, pos_.x, pos_.y, pos_.z);
	matWorld = matScale * matRotX * matRotY * matRotZ * matPos * matUpperWorld;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_TRIANGLELIST,
		verIndex.size() / 3,
		&verIndex[0],
		sizeof ST_PC_VERTEX
	);
}

void cCube::render(D3DXMATRIXA16& matS, D3DXMATRIXA16& matX, D3DXMATRIXA16& matY, D3DXMATRIXA16& matZ,
                   D3DXMATRIXA16& matT)
{
	D3DXMATRIXA16 matWorld, matScale, matPos, matRotX, matRotY, matRotZ;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, scale_.x, scale_.y, scale_.z);
	D3DXMatrixRotationX(&matRotX, rotate_.x);
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXMatrixRotationZ(&matRotZ, rotate_.z);
	D3DXMatrixTranslation(&matPos, pos_.x, pos_.y, pos_.z);
	matWorld = matS * matScale * matX * matRotX * matY * matRotY * matZ * matRotZ * matT * matPos;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_TRIANGLELIST,
		verIndex.size() / 3,
		&verIndex[0],
		sizeof ST_PC_VERTEX
	);
}

void cCube::update()
{
	//if (GetKeyState('q') & 0x8000 || GetKeyState('Q') & 0x8000)
	//{
	//	scale_ += D3DXVECTOR3(-0.1, -0.1, -0.1);
	//	pos.y += -0.1f;
	//}
	//else if (GetKeyState('e') & 0x8000 || GetKeyState('E') & 0x8000)
	//{
	//	scale_ += D3DXVECTOR3(0.1, 0.1, 0.1);
	//	pos.y += 0.1f;
	//}
	
	if (GetKeyState('a') & 0x8000 || GetKeyState('A') & 0x8000)
		rotate_.y = (rotate_.y / D3DX_PI * 180 - 5) * D3DX_PI / 180;
	else if (GetKeyState('d') & 0x8000 || GetKeyState('D') & 0x8000)
		rotate_.y = (rotate_.y / D3DX_PI * 180 + 5) * D3DX_PI / 180;
	
	if (GetKeyState('w') & 0x8000 || GetKeyState('W') & 0x8000)
		move(1);
	else if (GetKeyState('s') & 0x8000 || GetKeyState('S') & 0x8000)
		move(-1);

}

D3DXVECTOR3 cCube::move(float dir)
{
	if(dir == 0)
		return {};
	D3DXMATRIXA16 matRotY;
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXVECTOR3 temp_go;// = cVector3::transformCoord(direct_, cMatrix::rotationY(rotate_.Y)).normalize();
	D3DXVec3TransformNormal(&temp_go, &direct_, &matRotY);
	temp_go *= dir * speed;
	pos_ += temp_go;
	return temp_go;
}

