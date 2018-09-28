#pragma once

class tile;
class tileManager : public singletonBase<tileManager>
{
private:
	int tileFirstX, tileFirstY;
	int lastArrX, lastArrY;

	std::map<string, tile**> tileSets;

public:
	HRESULT init();
	void render(const char *stageName);

	void maketilestage(const char *stageName, int *tilePattern);
	void pushTile(const char *stageName, const char *imageName, int _arrayY, int _arrayX, int _state, bool _setCheck);

	tile **GetTileList(const char *stageName);
	int GetTileLastArrX() {
		return lastArrX;
	}
	int GetTileLastArrY() {
		return lastArrY;
	}
	tileManager();
	virtual ~tileManager();
};
