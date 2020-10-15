#include "stdafx.h"
#include "cAseLoader.h"

#include "cGroupNode.h"

cAseLoader::cAseLoader()
{
}

cAseLoader::~cAseLoader()
{
}

void cAseLoader::Load(vector<cGroupNode*>& vecGroupNode, char* szFolder, char* szFile)
{
	vector<D3DXVECTOR3> vecV;
	vector<D3DXVECTOR2> vecVT;
	vector<D3DXVECTOR3> vecVN;
	vector<ST_PNT_VERTEX> vecVertex;

	string sFullPath(szFolder);
	sFullPath += string("/") + string(szFile);

	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	//string sMtlName;
	while (true)
	{
		if (feof(fp))
			break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);
		string sTemp(szTemp);
		if(sTemp.find('*') == string::npos)
			continue;
		sTemp = sTemp.substr(sTemp.find('*'));
		
			
		
		if(sTemp.find("*SCENE ") != string::npos)
		{
			
		}
		else if (sTemp.find("*MATERIAL ") != string::npos)
		{
			int num;
			sscanf_s(sTemp.c_str(), "%*s %d %*s", &num);
			if(m_vecMtlTex.size() == num)
			{
				m_vecMtlTex.push_back(new cMtlTex);
			}
			while(true)
			{
				char szMtlTemp[1024];
				fgets(szMtlTemp, 1024, fp);
				string sMtlTemp(szMtlTemp);
				if (sMtlTemp.find('*') == string::npos)
					break;

				sMtlTemp = sMtlTemp.substr(sMtlTemp.find('*'));

				
				float x, y, z;
				if (sMtlTemp.find("*MATERIAL_AMBIENT ") != string::npos)
				{
					sscanf_s(sMtlTemp.c_str(), "%*s %f\t%f\t%f", &x, &y, &z);
					m_vecMtlTex[num]->GetMaterial().Ambient = D3DXCOLOR(x, y, z, 1.0f);
				}
				else if (sMtlTemp.find("*MATERIAL_DIFFUSE ") != string::npos)
				{
					sscanf_s(sMtlTemp.c_str(), "%*s %f %f %f", &x, &y, &z);
					m_vecMtlTex[num]->GetMaterial().Diffuse = D3DXCOLOR(x, y, z, 1.0f);
				}
				else if (sMtlTemp.find("*MATERIAL_SPECULAR ") != string::npos)
				{
					sscanf_s(sMtlTemp.c_str(), "%*s %f\t%f\t%f", &x, &y, &z);
					m_vecMtlTex[num]->GetMaterial().Specular = D3DXCOLOR(x, y, z, 1.0f);
				}
				else if (sMtlTemp.find("*BITMAP ") != string::npos)
				{
					char szLink[1024];
					sscanf_s(sMtlTemp.c_str(), "%*s %s", szLink, 1024);
					string sLink(szLink);
					sLink = sLink.substr(sLink.find_first_of('\"') + 1, sLink.find_last_of('\"') - 1);
					sLink = string(szFolder) + string("/") + sLink;

					LPDIRECT3DTEXTURE9 pTexture = g_pTextureManager.GetTexture(sLink);
					m_vecMtlTex[num]->SetTexture(pTexture);
				}
			}
			
		}
		else if (sTemp.find("*GEOMOBJECT") != string::npos)
		{
			cGroupNode* node = new cGroupNode;
			D3DXMATRIXA16 matWorld;
			D3DXMatrixIdentity(&matWorld);
			vecVT.clear(), vecV.clear(), vecVN.clear(), vecVertex.clear();
			
			while (true)
			{
				char szNodeTemp[1024];
				fgets(szNodeTemp, 1024, fp);
				string sNodeTemp(szNodeTemp);

				if (sNodeTemp.find('*') == string::npos)
				{
					if (sNodeTemp.find('{') == string::npos)
						break;
					continue;
				}
				
				sNodeTemp = sNodeTemp.substr(sNodeTemp.find('*'));
				
				
				if (sNodeTemp.find("*NODE_NAME ") != string::npos)
				{
					//char szName[1024];
					//sscanf_s(&sNodeTemp[11], "%s", szName, 1024);
					string sName(&sNodeTemp[11]);
					sName = sName.substr(sName.find_first_of('\"') + 1, sName.find_last_of('\"') - 1);
					node->SetName(sName);
				}
				else if (sNodeTemp.find("*NODE_PARENT ") != string::npos)
				{
					//char szParent[1024];
					//sscanf_s(sNodeTemp.c_str(), "%*s %s", szParent, 1024);
					string sParent(&sNodeTemp[13]);
					sParent = sParent.substr(sParent.find_first_of('\"') + 1, sParent.find_last_of('\"') - 1);
					//if(sParent.find(' ') != string::npos)
					//	sParent = sParent.substr(sParent.find_last_of(' ') + 1);

					for (auto * group_node : vecGroupNode)
					{
						if(group_node->GetName() == sParent)
						{
							//parent = group_node;
							group_node->AddChild(node);
							node->SetParentWorldTM(&group_node->GetWorldTM());
							break;
						}
					}
				}
				else if (sNodeTemp.find("*NODE_TM ") != string::npos)
				{
					while (true)
					{
						char szTMTemp[1024];
						fgets(szTMTemp, 1024, fp);
						string sTMTemp(szTMTemp);

						if (sTMTemp.find('*') == string::npos)
							break;

						sTMTemp = sTMTemp.substr(sTMTemp.find('*'));


						if (sTMTemp.find("*TM_ROW0 ") != string::npos)
						{
							sscanf_s(sTMTemp.c_str(), "%*s %f %f %f", &matWorld.m[0][0], &matWorld.m[0][2], &matWorld.m[0][1]);
						}																				
						else if (sTMTemp.find("*TM_ROW1 ") != string::npos)								
						{																				
							sscanf_s(sTMTemp.c_str(), "%*s %f %f %f", &matWorld.m[2][0], &matWorld.m[2][2], &matWorld.m[2][1]);
						}																				
						else if (sTMTemp.find("*TM_ROW2 ") != string::npos)								
						{																				
							sscanf_s(sTMTemp.c_str(), "%*s %f %f %f", &matWorld.m[1][0], &matWorld.m[1][2], &matWorld.m[1][1]);
						}																				
						else if (sTMTemp.find("*TM_ROW3 ") != string::npos)								
						{																				
							sscanf_s(sTMTemp.c_str(), "%*s %f %f %f", &matWorld.m[3][0], &matWorld.m[3][2], &matWorld.m[3][1]);
							node->SetWorldTM(matWorld);
							D3DXMATRIXA16 matI;
							D3DXMatrixIdentity(&matI);
							if (node->GetParentWorldTM())
							{
								float det = D3DXMatrixDeterminant(node->GetParentWorldTM());
								D3DXMatrixInverse(&matI, &det, node->GetParentWorldTM());
							}
							matI = matWorld * matI;
							node->SetLocalTM(matI);
						}
					}
				}
				else if (sNodeTemp.find("*MESH ") != string::npos)
				{
					while (true)
					{
						char szMeshTemp[1024];
						fgets(szMeshTemp, 1024, fp);
						string sMeshTemp(szMeshTemp);

						if (sMeshTemp.find('*') == string::npos)
							break;

						sMeshTemp = sMeshTemp.substr(sMeshTemp.find('*'));

						if (sMeshTemp.find("*MESH_VERTEX_LIST ") != string::npos)
						{
							while(true)
							{
								char szVertexTemp[1024];
								fgets(szVertexTemp, 1024, fp);
								string sVertexTemp(szVertexTemp);

								if (sVertexTemp.find('*') == string::npos)
									break;

								sVertexTemp = sVertexTemp.substr(sVertexTemp.find('*'));

								
								float x, y, z;
								sscanf_s(sVertexTemp.c_str(), "%*s %*d %f %f %f", &x, &z, &y);
								vecV.emplace_back(x, y, z);
							}
						}
						else if (sMeshTemp.find("*MESH_FACE_LIST ") != string::npos)
						{
							ST_PNT_VERTEX v{};
							while (true)
							{
								char szVertexTemp[1024];
								fgets(szVertexTemp, 1024, fp);
								string sVertexTemp(szVertexTemp);
								if (sVertexTemp.find('*') == string::npos)
									break;
								sVertexTemp = sVertexTemp.substr(sVertexTemp.find('*'));

								
								
								int x, y, z;
								sscanf_s(sVertexTemp.c_str(), "%*s %*d: A: %d B: %d C: %d", &x, &z, &y);
								v.p = vecV[x];	vecVertex.emplace_back(v);
								v.p = vecV[y];	vecVertex.emplace_back(v);
								v.p = vecV[z];	vecVertex.emplace_back(v);
							}
						}
						else if (sMeshTemp.find("*MESH_TVERTLIST ") != string::npos)
						{
							while (true)
							{
								char szVertexTemp[1024];
								fgets(szVertexTemp, 1024, fp);
								string sVertexTemp(szVertexTemp);

								if (sVertexTemp.find('*') == string::npos)
									break;
								
								sVertexTemp = sVertexTemp.substr(sVertexTemp.find('*'));

								
								float x, y;
								sscanf_s(sVertexTemp.c_str(), "%*s %*d %f %f %*f", &x, &y);
								y = 1.0f - y;
								vecVT.emplace_back(x, y);
							}
						}
						else if (sMeshTemp.find("*MESH_TFACELIST ") != string::npos)
						{
							int i = 0;
							while (true)
							{
								char szVertexTemp[1024];
								fgets(szVertexTemp, 1024, fp);
								string sVertexTemp(szVertexTemp);

								if (sVertexTemp.find('*') == string::npos)
									break;

								sVertexTemp = sVertexTemp.substr(sVertexTemp.find('*'));

								

								int x, y, z;
								sscanf_s(sVertexTemp.c_str(), "%*s %*d %d %d %d", &x, &z, &y);
								vecVertex[i + 0].t = vecVT[x];
								vecVertex[i + 1].t = vecVT[y];
								vecVertex[i + 2].t = vecVT[z];
								i += 3;
							}
						}
						else if (sMeshTemp.find("*MESH_NORMALS ") != string::npos)
						{
							int i = 0;
							while (true)
							{
								char szNormalTemp[1024];
								fgets(szNormalTemp, 1024, fp);
								string sVertexTemp(szNormalTemp);

								if (sVertexTemp.find('*') == string::npos)
									break;
								if (sVertexTemp.find("*MESH_VERTEXNORMAL ") == string::npos)
									continue;

								sVertexTemp = sVertexTemp.substr(sVertexTemp.find('*'));


								float x, y, z; int a;
								sscanf_s(sVertexTemp.c_str(), "%*s %*d %f %f %f", &x, &z, &y);
								vecVertex[i].n = D3DXVECTOR3(x, y, z);
								i++;
							}
						}
					}
				}
				else if (sNodeTemp.find("*TM_ANIMATION ") != string::npos)
				{
					while (true)
					{
						char szAnimTemp[1024];
						fgets(szAnimTemp, 1024, fp);
						string sAnimTemp(szAnimTemp);

						if (sAnimTemp.find('*') == string::npos)
							break;
						sAnimTemp = sAnimTemp.substr(sAnimTemp.find('*'));

						if (sAnimTemp.find("*CONTROL_POS") != string::npos)
						{
							while (true)
							{
								char szPosTemp[1024];
								fgets(szPosTemp, 1024, fp);
								string sPosTemp(szPosTemp);

								if (sPosTemp.find('*') == string::npos)
									break;
								sPosTemp = sPosTemp.substr(sPosTemp.find('*'));
							}
						}
						if (sAnimTemp.find("*CONTROL_ROT") != string::npos)
						{
							while (true)
							{
								char szRotTemp[1024];
								fgets(szRotTemp, 1024, fp);
								string sRotTemp(szRotTemp);

								if (sRotTemp.find('*') == string::npos)
									break;
								sRotTemp = sRotTemp.substr(sRotTemp.find('*'));
							}
						}
					}
				}
				else if (sNodeTemp.find("*MATERIAL_REF ") != string::npos)
				{
					int index;
					sscanf_s(sNodeTemp.c_str(), "%*s %d", &index);
					node->SetMtlTex(m_vecMtlTex[index]);
				}
			}

			node->SetVertex(vecVertex);
			
			vecGroupNode.push_back(node);
		}
		
	}

	fclose(fp);

	for (auto * it : m_vecMtlTex)
	{
		SafeRelease(it);
	}
	m_vecMtlTex.clear();
}
