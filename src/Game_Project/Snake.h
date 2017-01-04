#pragma once
#include <vector>
#include "Sprites.h"
using namespace std;

class Snake{
public:
	vector<Sprite> conjuntoSerp;
    Snake();
	void Mov();
	void Update(void) ;
	void Draw(void) ;
	void Push();
	int dir = 0;
	int iPosX;
	int iPosY;
	int tamaño;

	int posX;
	int posY;

	int prevPosX;
	int prevPosY;

	int uPosX;
	int uPosY;

	Uint64 timer;
	Uint64 prevTime;

	Sprite head;
	Sprite body;
	Sprite tail;
private:
};