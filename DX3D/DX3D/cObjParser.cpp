#include "stdafx.h"
#include "cObjParser.h"
#include <fstream>
#include <iostream>

#include "cMtlParser.h"
using std::ifstream;

cObjParser::cObjParser() : m_stMtl(), m_pTexture(nullptr), m_sRoot()
{
}

cObjParser::cObjParser(string file): m_stMtl(), m_pTexture(nullptr)
{
	if (open(file))
		std::cout << "파일을 열지 못했습니다.\n";
}

cObjParser::~cObjParser()
{
}

int cObjParser::open(string file)
{
	string temp = m_sRoot + file;
	ifstream is(temp);
	//ifstream is;
	//is.open("data/obj/box.obj");

	//FILE* fp = fopen(temp.c_str(), "r");
	//is.seekg(0);
	if (is.is_open())
	{
		while(!is.eof())
		{
			char arr[256];
			is.getline(arr, 256);
			oFile.emplace_back(arr);
		}
		return 0;
	}

	return -1;
}

void cObjParser::objParse()
{
	vector<D3DXVECTOR3> vecIndex;
	vector<D3DXVECTOR2> vecTexture;
	vector<D3DXVECTOR3> vecNormal;
	char* arr = new char[256];
	string mtladdr;
	for (auto & line : oFile)
	{
		if (line.empty())
			continue;

		strcpy_s(arr, 256, line.c_str());

		char* token = strtok(arr, " ");

		if (strncmp(token, "#", 1) == 0)
		{
			continue;
		}
		else if (strcmp(token, "mtllib") == 0)
		{
			token = strtok(NULL, " ");
			mtladdr = token;
		}
		else if (strcmp(token, "g") == 0)
		{
			token = strtok(NULL, " ");
			if (token != NULL)
				m_sGroupID = token;
		}
		else if (strcmp(token, "v") == 0)
		{
			D3DXVECTOR3 v;
			token = strtok(NULL, " ");
			v.x = atof(token);

			token = strtok(NULL, " ");
			v.y = atof(token);

			token = strtok(NULL, " ");
			v.z = atof(token);
			vecIndex.push_back(v);
		}
		else if (strcmp(token, "vt") == 0)
		{
			D3DXVECTOR2 v;
			token = strtok(NULL, " ");
			v.x = atof(token);

			token = strtok(NULL, " ");
			v.y = atof(token);

			vecTexture.push_back(v);
		}
		else if (strcmp(token, "vn") == 0)
		{
			D3DXVECTOR3 v;
			token = strtok(NULL, " ");
			v.x = atof(token);

			token = strtok(NULL, " ");
			v.y = atof(token);

			token = strtok(NULL, " ");
			v.z = atof(token);
			D3DXVec3Normalize(&v, &v);
			vecNormal.push_back(v);
		}
		else if (strcmp(token, "usemtl") == 0)
		{
			token = strtok(NULL, " ");
			cMtlParser mtlParser;
			mtlParser.setRoot(m_sRoot);
			mtlParser.open(mtladdr);
			mtlParser.mtlParse();
			m_stMtl = mtlParser.createMtl(token, m_pTexture);
			
		}
		else if (strcmp(token, "s") == 0)
		{
			continue;
		}
		else if (strcmp(token, "f") == 0)
		{
			ST_PNT_VERTEX v;
			for (int i = 0; i < 3; ++i)
			{
				
				token = strtok(NULL, "/ ");
				v.p = vecIndex[atoi(token) - 1];

				token = strtok(NULL, "/ ");
				v.t = vecTexture[atoi(token) - 1];

				token = strtok(NULL, "/ ");
				v.n = vecNormal[atoi(token) - 1];

				m_vecVertex.push_back(v);
			}
			
		}
		
	}

	D3DXVECTOR3 u, v, n;
	const int length = m_vecVertex.size();
	for (int i = 0; i < length; i += 3)
	{
		u = m_vecVertex[i + 1].p - m_vecVertex[i].p;
		v = m_vecVertex[i + 2].p - m_vecVertex[i].p;

		D3DXVec3Cross(&n, &u, &v);
		D3DXVec3Normalize(&n, &n);

		m_vecVertex[i + 0].n = n;
		m_vecVertex[i + 1].n = n;
		m_vecVertex[i + 2].n = n;
	}

	delete[] arr;
}

void cObjParser::createObj(vector<ST_PNT_VERTEX>& vertex, D3DMATERIAL9* mtl, LPDIRECT3DTEXTURE9& texture)
{
	vertex.assign(m_vecVertex.begin(), m_vecVertex.end());
	*mtl = m_stMtl;
	texture = m_pTexture;
}
