#pragma once
#include "Scene.h"
#include <vector>
#include "Sprites.h"
using namespace std;
class Snake
{

public:
	Snake();
	~Snake();
	void Draw(void);
	void Update(void);
	void Move(int dir);
	void changeDir();
	vector<pair<int, int>> coord;

private:

	int dir;
	int vel;

};