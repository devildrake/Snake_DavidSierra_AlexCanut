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
	tama�o = 3;
	timer = 1000000;
	prevTime = TM.GetCurTime();
	//anim.push_back(tail);

	


}
void Snake::Push(){
}
void Snake::Mov() {
	if (IM.IsKeyDown<KEY_BUTTON_DOWN>() && dir != 3) {
		dir = 4;
	}
	else if (IM.IsKeyDown<KEY_BUTTON_UP>() && dir != 4) {
		dir = 3;
	}
	else if (IM.IsKeyDown<KEY_BUTTON_RIGHT>() && dir != 2) {
		dir = 1;
	}
	else if (IM.IsKeyDown<KEY_BUTTON_LEFT>() && dir != 1) {
		dir = 2;
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
		cout << "Move\n";
		cout << "Resta:   " << TM.GetCurTime() - prevTime;

		cout << "CURRENTIME:: " << TM.GetCurTime() << endl;

		cout << "CURRENTIME:: " << TM.GetCurTime() << endl;


		cout << timer << endl;
		switch (dir) {
			prevPosX = posX;
			prevPosY = posY;
		case 0:
			break;
		case 1: //IZQUIERDA?

			posX -= 1;
			break;
		case 2:
			posX += 1;

			break;
		case 3:
			posY -= 1;


			break;
		case 4:
			posY += 1;
			break;

		}
		prevTime = TM.GetCurTime();
		cout << "PrevTIME::  " << prevTime << endl;
	}
}

void Snake::Update() {
	Mov();
}
void Snake::Draw(void) {
	for (int i = 0; i < conjuntoSerp.size(); i++) {
		conjuntoSerp[i].Draw();
	}
}