#pragma once
#include <queue>
#include <list>
//#include "cCharacter.h"
class cCharacter;
enum class animState;
using std::queue;
using std::list;

struct to_dir
{
	string xy;
	short distance;
	to_dir() : xy(""), distance(0) {}
	to_dir(string xy, short dis) : xy(xy), distance(dis) {}
};

class cAnimChar
{
private:
	static vector<vector<short>> keyFrameData;
	static vector<vector<to_dir>> moveData;
	static vector<vector<to_dir>> cameraMove;
	static vector<vector<short>> keyUnlock;
	queue<to_dir> cameraQ;
	queue<short> unlockQ;
	queue<to_dir> moveQ;
	queue<short> frameData;
	//short remain_frame;
	bool current_foot;
	friend class cAnimCharLoader;
public:
	cAnimChar();
	~cAnimChar();
	void setAnim(animState anim);
	void playAnim(cCharacter* target);
	short getRemainFrame() const { return frameData.size(); }
};

//vector<vector<short>> cAnimChar::keyFrameData = vector<vector<short>>();
//vector<vector<to_dir>> cAnimChar::moveData = vector<vector<to_dir>>();
//vector<vector<to_dir>> cAnimChar::cameraMove = vector<vector<to_dir>>();
//vector<vector<short>> cAnimChar::keyUnlock = vector<vector<short>>();

