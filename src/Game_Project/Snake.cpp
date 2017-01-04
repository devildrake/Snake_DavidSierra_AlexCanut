#include "Snake.h"
#include "GameScene.h"
#include "Niveles.h"
#include "ID.h"
#include "InputManager.h"
#include "TimeManager.h"
#include <time.h>
#include "Logger.h"
#include "SceneManager.h"

using namespace Logger;

Snake::Snake() {
	head.transform = { W.GetWidth()/2, W.GetHeight() / 2, W.GetWidth() / 40, W.GetHeight() / 40 };
	head.objectID = ObjectID::S_08;
	body.transform = { head.transform.x- head.transform.w , head.transform.y, W.GetWidth() / 40, W.GetHeight() / 40 };
	body.objectID = ObjectID::S_09;
	tail.transform = { body.transform.x- body.transform.w , body.transform.y , W.GetWidth() / 40, W.GetHeight() / 40 };
	tail.objectID = ObjectID::S_09;

	isAlive = true;



	conjuntoSerp.push_back(head);
	conjuntoSerp.push_back(body);
	conjuntoSerp.push_back(tail);

	tamaño = 3;
	timer = 1000000;
	prevTime = TM.GetCurTime();
	hasMoved = false;
	isBlocked = false;
	srand(time(NULL));
	//anim.push_back(tail);
}
void Snake::AñadirTrozo() {
	Sprite newNode;
	newNode.objectID = ObjectID::S_09;
	newNode.transform = conjuntoSerp[tamaño - 1].transform;
	
	conjuntoSerp.push_back(newNode);
	tamaño++;
}
void Snake::Mov() {

	if (!isBlocked&&isAlive) {

		if (IM.IsKeyDown<KEY_BUTTON_DOWN>() && dir != 3) {
			isBlocked = true;
			dir = 4;
		}
		else if (IM.IsKeyDown<KEY_BUTTON_UP>() && dir != 4) {
			isBlocked = true;
			dir = 3;
		}
		else if (IM.IsKeyDown<KEY_BUTTON_RIGHT>() && dir != 2) {
			isBlocked = true;
			dir = 1;
		}
		else if (IM.IsKeyDown<KEY_BUTTON_LEFT>() && dir != 1) {
			isBlocked = true;
			dir = 2;
		}
	}
	

	if ((TM.GetCurTime() - prevTime) > timer) {
		cout << "Posicion Tabla Snake:  X:   " << posX << "  Y:  " << posY << endl;
		if (isAlive) {
			switch (dir) {
			case 0:
				prevPosX = posX;
				prevPosY = posY;
				break;
			case 1: //IZQUIERDA?
				prevPosX = posX;
				prevPosY = posY;
				posX += 1;
				hasMoved = true;
				break;
			case 2:
				prevPosX = posX;
				prevPosY = posY;
				posX -= 1;
				hasMoved = true;
				break;
			case 3:
				prevPosX = posX;
				prevPosY = posY;
				posY -= 1;
				hasMoved = true;
				break;
			case 4:
				prevPosX = posX;
				prevPosY = posY;
				posY += 1;
				hasMoved = true;
				break;

			}
			prevTime = TM.GetCurTime();
		}
	}
}

void Snake::ChangeLast() {
	if (isAlive) {
		Sprite temp;
		temp = conjuntoSerp[tamaño - 1];
		conjuntoSerp[tamaño - 1] = conjuntoSerp[tamaño - 2];
		conjuntoSerp[tamaño - 2] = temp;
	}
}

void Snake::Update() {
	if(isAlive)
	Mov();

}
void Snake::Draw(void) {
	if (isAlive) {
		for (int i = 0; i < conjuntoSerp.size(); i++) {
			conjuntoSerp[i].Draw();
		}
	}
}