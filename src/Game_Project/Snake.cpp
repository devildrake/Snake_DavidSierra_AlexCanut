#include "Snake.h"
#include "LevelScene.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


Snake::Snake() {
	/*anim.begin = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_08 };
	anim.end = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_10 };*/
	std::pair<int, int> posCabOrg = {0, 0};
	dir = 0;
	coord.push_back(posCabOrg);
	coord[0].first = coord[0].second = 0;

}
Snake::~Snake() {
}
void Snake::Update(void) {

	switch (dir) {
	case 0:
		coord[0].second--;
		break;
	case 1:
		coord[0].second++;
		break;
	case 2:
		coord[0].first++;
		break;
	case 3:
		coord[0].first++;
		break;
	}


}
void Snake::Move(int dir) {

}

void Snake::changeDir() {

}
void Snake::Draw(void) {
	/*for (vector<Sprite>::iterator it = anim.begin; it != anim.end; it++) {
		
	}*/
}