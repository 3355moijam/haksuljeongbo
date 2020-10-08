#include "stdafx.h"
#include "cMtlParser.h"
#include <fstream>
#include <iostream>

cMtlParser::cMtlParser()
{
}

cMtlParser::cMtlParser(string file)
{
	if (open(file))
		std::cout << "파일을 열지 못했습니다.\n";
}

cMtlParser::~cMtlParser()
{
}

int cMtlParser::open(string file)
{
	std::ifstream is(m_sRoot + file);
	if (is.is_open())
	{
		while (!is.eof())
		{
			char arr[256];
			is.getline(arr, 256);
			oFile.emplace_back(arr);
		}
		return 0;
	}

	return -1;
}

void cMtlParser::mtlParse()
{
	D3DMATERIAL9 mtl{};
	
	for (auto& line : oFile)
	{
		if (line.empty())
			continue;

		if (strncmp(line.c_str(), "#", 1) == 0 ||
			strncmp(line.c_str(), "d", 1) == 0 || 
			strncmp(line.c_str(), "Ns", 2) == 0 || 
			strncmp(line.c_str(), "illum", 5) == 0)
			continue;
		else if(strncmp(line.c_str(), "newmtl", 6)== 0)
		{
			char temp[32];
			sscanf_s(line.c_str(), "%*s %s", temp, sizeof temp);
			m_mtlName.emplace_back(temp);
		}
		else if(strncmp(line.c_str(), "Ka", 2) == 0)
		{
			float x, y, z;
			sscanf_s(line.c_str(), "%*s %f %f %f", &x, &y, &z);
			mtl.Ambient = D3DXCOLOR(x, y, z, 1.0f);
		}
		else if (strncmp(line.c_str(), "Kd", 2) == 0)
		{
			float x, y, z;
			sscanf_s(line.c_str(), "%*s %f %f %f", &x, &y, &z);
			mtl.Diffuse = D3DXCOLOR(x, y, z, 1.0f);
		}
		else if (strncmp(line.c_str(), "Ks", 2) == 0)
		{
			float x, y, z;
			sscanf_s(line.c_str(), "%*s %f %f %f", &x, &y, &z);
			mtl.Specular = D3DXCOLOR(x, y, z, 1.0f);
			m_mtlList.push_back(mtl);
		}
		else if(strncmp(line.c_str(), "map_Kd", 6) == 0)
		{
			char temp[32];
			sscanf_s(line.c_str(), "%*s %s", temp, sizeof temp);
			m_textureAddr.push_back(m_sRoot + temp);
		}
	}
}

D3DMATERIAL9 cMtlParser::createMtl(string name, LPDIRECT3DTEXTURE9& texture)
{
	int i;
	for (i = 0; i < m_mtlName.size(); ++i)
	{
		if (m_mtlName[i].compare(name) == 0)
			break;
	}
	
	std::wstring wAddr;
	wAddr.assign(m_textureAddr[i].begin(), m_textureAddr[i].end());

	D3DXCreateTextureFromFile(g_pD3DDevice, wAddr.c_str(), &texture);

	return m_mtlList[i];
}
