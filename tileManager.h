#pragma once

class tile;
class tileManager : public singletonBase<tileManager>
{
private:
	int tileFirstX, tileFirstY;
	int lastArrX, lastArrY;

	string stageName;
	std::map<string, tile**> tileSets;

public:
	HRESULT init(string _stageName);
	void render(const char *_stageName);

	void maketilestage(const char *_stageName, int *tilePattern);
	void pushTile(const char *_stageName, const char *imageName, int _arrayY, int _arrayX, int _state, bool _setCheck);
	

	tile **GetTileList(const char *_stageName);
	int GetTileLastArrX() {
		return lastArrX;
	}
	int GetTileLastArrY() {
		return lastArrY;
	}

	string GetStageName()
	{
		return stageName;
	}
	tileManager();
	virtual ~tileManager();
};
