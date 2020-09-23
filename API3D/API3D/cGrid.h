#pragma once
class cMatrix;
class cVector3;
class cGrid
{
private:
	float interval;
	vector<cVector3> top;
	vector<cVector3> bottom;
	vector<cVector3> left;
	vector<cVector3> right;
public:
	cGrid();
	void render(HDC hdc, cMatrix& matWVP, cMatrix& matViewport);
};
