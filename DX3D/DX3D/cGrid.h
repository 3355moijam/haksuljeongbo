#pragma once

class cGrid
{
private:
	float interval;
	float size;
	//vector<ST_PC_VERTEX> top;
	//vector<ST_PC_VERTEX> bottom;
	//vector<ST_PC_VERTEX> left;
	//vector<ST_PC_VERTEX> right;
	vector<ST_PC_VERTEX> vertex;
	vector<ST_PC_VERTEX> gizmoVertex;
	vector<ST_PC_VERTEX> axisVertex;
public:
	cGrid();
	void render();
};
