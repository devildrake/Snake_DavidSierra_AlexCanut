#pragma once
#include "Sprites.h"
#include "ID.h"
#include <iostream>

class Tabla {
public:
	Tabla();
	~Tabla();
	void Draw(void);
	void crearTabla(int,int);

	Sprite** sprites;
	int numC, numR;
private:

	bool wasMade;
};
