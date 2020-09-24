#include "stdafx.h"
#include "cGrid.h"


cGrid::cGrid() :
	interval(1), size(50)
{
	for (int i = 0; i < size + 1; ++i)
	{
		D3DCOLOR color;
		if (i % 5)
			color = D3DCOLOR_XRGB(50, 50, 50);
		else
			color = D3DCOLOR_XRGB(255, 255, 255);

		float tempTerm = size * 0.5;
		vertex.emplace_back(interval * -tempTerm + i * interval, 0, interval * -tempTerm, color);
		vertex.emplace_back(interval * -tempTerm + i * interval, 0, interval * tempTerm, color);
		vertex.emplace_back(interval * -tempTerm, 0, interval * -tempTerm + i * interval, color);
		vertex.emplace_back(interval * tempTerm, 0, interval * -tempTerm + i * interval, color);
		
		//top.emplace_back(interval * -5 + i * interval, 0, interval * -5, color);
		//bottom.emplace_back(interval * -5 + i * interval, 0, interval * 5, color);
		//left.emplace_back(interval * -5, 0, interval * -5 + i * interval, color);
		//right.emplace_back(interval * 5, 0, interval * -5 + i * interval, color);
	}
	D3DCOLOR red = D3DCOLOR_XRGB(255, 0, 0);
	D3DCOLOR green = D3DCOLOR_XRGB(0, 255, 0);
	D3DCOLOR blue = D3DCOLOR_XRGB(0, 0, 255);
	gizmoVertex.emplace_back(10		, 0		, 0		, red);
	gizmoVertex.emplace_back(9		, 0.1	, 0.1	, red);
	gizmoVertex.emplace_back(9		, -0.1	, 0.1	, red);
	gizmoVertex.emplace_back(9		, -0.1	, -0.1	, red);
	gizmoVertex.emplace_back(9		, 0.1	, -0.1	, red);
	gizmoVertex.emplace_back(9		, 0.1	, 0.1	, red);

	gizmoVertex.emplace_back(0		, 10	, 0		, green);
	gizmoVertex.emplace_back(0.1	, 9		, 0.1	, green);
	gizmoVertex.emplace_back(-0.1	, 9		, 0.1	, green);
	gizmoVertex.emplace_back(-0.1	, 9		, -0.1	, green);
	gizmoVertex.emplace_back(0.1	, 9		, -0.1	, green);
	gizmoVertex.emplace_back(0.1	, 9		, 0.1	, green);

	gizmoVertex.emplace_back(0		, 0		, 10	, blue);
	gizmoVertex.emplace_back(0.1	, 0.1	, 9		, blue);
	gizmoVertex.emplace_back(0.1	, -0.1	, 9		, blue);
	gizmoVertex.emplace_back(-0.1	, -0.1	, 9		, blue);
	gizmoVertex.emplace_back(-0.1	, 0.1	, 9		, blue);
	gizmoVertex.emplace_back(0.1	, 0.1	, 9		, blue);



	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(0, 0, 0);
	axisVertex.emplace_back(v);

	v.p = D3DXVECTOR3(10, 0, 0);
	axisVertex.emplace_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, 0, 0);
	axisVertex.emplace_back(v);

	v.p = D3DXVECTOR3(0, 10, 0);
	axisVertex.emplace_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, 0);
	axisVertex.emplace_back(v);

	v.p = D3DXVECTOR3(0, 0, 10);
	axisVertex.emplace_back(v);
}

void cGrid::render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_LINELIST,
		vertex.size() * 0.5,
		&vertex[0],
		sizeof ST_PC_VERTEX
	);

	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_LINELIST,
		axisVertex.size() * 0.5,
		&axisVertex[0],
		sizeof ST_PC_VERTEX
	);
	
	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_TRIANGLEFAN,
		4,
		&gizmoVertex[0],
		sizeof ST_PC_VERTEX
	);

	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_TRIANGLEFAN,
		4,
		&gizmoVertex[6],
		sizeof ST_PC_VERTEX
	);

	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_TRIANGLEFAN,
		4,
		&gizmoVertex[12],
		sizeof ST_PC_VERTEX
	);
}
