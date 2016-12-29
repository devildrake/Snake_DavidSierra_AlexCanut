#pragma once
#include <vector>
#include "Sprites.h"
using namespace std;

class Snake{
public:
	vector<Sprite> anim;
    Snake();
	void Mov();
	void Update(void) ;
	void Draw(void) ;
	void Push();
	int dir = 0;
	Sprite head;
	Sprite body;
	Sprite tail;
private:
};