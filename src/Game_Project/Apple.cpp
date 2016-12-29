#include "Apple.h"
#include "ID.h"
#include "InputManager.h"
#include "TimeManager.h"
#include <time.h>
#include "Logger.h"
#include "SceneManager.h"

using namespace Logger;

Apple::Apple(GameScene* gs) {
	laScene = gs;
	laManzana.objectID = ObjectID::S_11;
	changePos;
}

Apple::~Apple() {
}

void Apple::Draw() {
	laManzana.Draw();
}


void Apple:: Update() {
	laManzana.transform = laScene->tabla[posX][posY].transform;
}

void Apple::changePos() {
	posX = rand() % laScene->numC;
	posY = rand() % laScene->numR;
}


/*Apple::Apple() {

}

Apple::Apple(int rows, int columns) {

	numR = rows;
	numC = columns;

	laTabla = new Sprite*[numR];
	for (int i = 0; i < numR; i++) laTabla[i] = new Sprite[numC];//por cada numero de filas se añaden el numero de columnas

	for (int i = 0; i < numR; i++) {
		for (int j = 0; j < numC; j++) {
			laTabla[i][0].transform = { i * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
				((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
			laTabla[i][numC - 1].transform = { i * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
				(numC - 1) * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
			laTabla[0][j].transform = { 0 + ((W.GetWidth() / 2 - ((numR / 2) * 20))) ,
				j * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
			laTabla[numR - 1][j].transform = { (numR - 1) * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
				j * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
			laTabla[i][j].objectID = ObjectID::S_11;
		}
	}


	numApple = 3;
	for (int i = 0; i < numApple; i++) {
		A.transform = { rand() % (laTabla[0][0].transform.x + laTabla[0][numR-1].transform.x),
			rand() % (laTabla[0][0].transform.y + laTabla[0][numR - 1].transform.y), W.GetWidth() / 40, W.GetHeight() / 40 };
		A.objectID = ObjectID::S_10;
		apple.push_back(A);
	}
}
Apple::~Apple() {

}
void Apple::Update() {

}
void Apple::Pop() {

}
void Apple::Draw() {
	for (int i = 0; i < apple.size() - 1; i++) {
		apple[i].Draw();
	}
}*/