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
	Sprite aAñadir;
	aAñadir.objectID = ObjectID::S_09;
	aAñadir.transform = conjuntoSerp[tamaño - 1].transform;
	conjuntoSerp.push_back(aAñadir);
	tamaño++;
}
void Snake::Mov() {

	if (!isBlocked) {

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
	/*switch (dir) {
	case 0: break;
	case 1:
			for (int i = anim.size()-1; i > 0; i--) {
				anim[i].transform.x = (anim[i-1].transform.x - anim[i-1].transform.w);
				anim[i].transform.y = anim[i-1].transform.y;
			}
			anim[0].transform.x += TM.GetDeltaTime()*200.f;
		break;
	case 2:
		for (int i = anim.size()-1; i > 0; i--) {
			anim[i].transform.x = (anim[i-1].transform.x + anim[i-1].transform.w);
			anim[i].transform.y = anim[i-1].transform.y;
		}
			anim[0].transform.x -= TM.GetDeltaTime()*200.f;

		break;
	case 3:
		for (int i = anim.size()-1; i > 0; i--) {
			anim[i].transform.x = anim[i-1].transform.x;
			anim[i].transform.y = anim[i-1].transform.y + anim[i-1].transform.h;
		}
			anim[0].transform.y -= TM.GetDeltaTime()*200.f;

		break;
	case 4:
		for (int i = anim.size()-1; i > 0; i--) {
			anim[i].transform.x = anim[i-1].transform.x;
			anim[i].transform.y = anim[i-1].transform.y - anim[i-1].transform.h;

		}
			anim[0].transform.y += TM.GetDeltaTime()*200.f;

		break;
	}*/

	if ((TM.GetCurTime() - prevTime) > timer) {
		//cout << "0:  X--> " << conjuntoSerp[0].transform.x << "  Y--> " << conjuntoSerp[0].transform.y << endl;
		//cout <<"1:  X--> "<< conjuntoSerp[1].transform.x <<"  Y--> "<< conjuntoSerp[1].transform.y<<endl;
		//cout << "2:  X--> " << conjuntoSerp[2].transform.x << "  Y--> " << conjuntoSerp[2].transform.y << endl;
		
		cout << "Posicion Tabla Snake:  X:   " << posX << "  Y:  " << posY << endl;

		//cout << "Move\n";
		//cout << "Resta:   " << TM.GetCurTime() - prevTime;
		//cout << "CURRENTIME:: " << TM.GetCurTime() << endl;
		//cout << "CURRENTIME:: " << TM.GetCurTime() << endl;
		//cout << timer << endl;
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
		//cout << "PrevTIME::  " << prevTime << endl;
		//cout << "posicion a cambiar::  " << posX << ", " << posY << endl;
		//cout << "PrevPos::  " << prevPosX << ", " << prevPosY << endl;

	}
}

void Snake::ChangeLast() {
	
	Sprite temp;
	temp = conjuntoSerp[tamaño - 1];
	conjuntoSerp[tamaño - 1] = conjuntoSerp[tamaño-2];
	conjuntoSerp[tamaño-2] = temp;
	
	//swap(conjuntoSerp[conjuntoSerp.size() - 1], conjuntoSerp[conjuntoSerp.size()-2]);




	cout << "Cola:  " << conjuntoSerp[tamaño - 1].transform.x << " , " << conjuntoSerp[tamaño - 1].transform.y << endl;
	cout << "Cuello:  " << conjuntoSerp[1].transform.x << " , " << conjuntoSerp[1].transform.y << endl;

	/*cout << "Temp:  " << temp.transform.x << " , " << temp.transform.y<<endl;
	*/

}

void Snake::Update() {
	Mov();

}
void Snake::Draw(void) {
	for (int i = 0; i < conjuntoSerp.size(); i++) {
		conjuntoSerp[i].Draw();
	}
}