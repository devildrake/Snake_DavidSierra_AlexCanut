#include "LevelScene.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include <XML/rapidxml_utils.hpp>
#include "GameScene.h"
#include <time.h>
#include "Snake.h"


using namespace Logger;

GameScene::GameScene() {
	snake = Snake();
	numR = 20;
	numC = 20;
	//LAS VARIABLES NUMR Y NUMC DEBERÍAN PODER LEERSE LUEGO DESDE XML
	tabla = new Sprite*[20];
	for (int i = 0; i < numR; i++) tabla[i] = new Sprite[numR];


	for (int i = 0; i < numC; i++) {
		for (int j = 0; j < 20; ++j) {
			tabla[0][i].transform = { 0 * (20) + ((W.GetWidth() - 20 * 20) >> 1), i*(20) + ((W.GetHeight() - 20 * 20) >> 1) ,50,50 };
			tabla[j][0].transform = { j*(20) + ((W.GetWidth() - 20 * 20) >> 1), 0 * (20) + ((W.GetHeight() - 20 * 20) >> 1), 50,50 };
			tabla[19][i].transform = { 19 * (20) + ((W.GetWidth() - 20 * 20) >> 1), i*(20) + ((W.GetHeight() - 20 * 20) >> 1) ,50,50 };
			tabla[j][19].transform = { j*(20) + ((W.GetWidth() - 20 * 20) >> 1), 19 * (20) + ((W.GetHeight() - 20 * 20) >> 1), 50,50 };
			tabla[i][j].objectID = ObjectID::S_12;
		}
	}

	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	manzana = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_11 };
	pared = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_12 };
	/*cabeza.objectID = ObjectID::S_08;
	cuerpo.objectID = ObjectID::S_09;
	cola.objectID = ObjectID::S_10;
	*/	cabeza = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_09 };
	
}
GameScene::~GameScene() {
}
void GameScene::OnEntry(void) {

}
void GameScene::OnExit(void) {

}

void GameScene::NewFruit() {
	manzana.transform = tabla[rand() % 15][rand() % 15].transform;
}

void GameScene::Update(void) {
	//NewFruit();

	//snake.cabeza.transform = tabla[snake.coord[0].first][snake.coord[0].second].transform;
	//cabeza.transform = tabla[snake.coord[0].first][snake.coord[0].second].transform;
	//tabla[snake.coord[0].first][snake.coord[0].second] = snake.cabeza;

	/*snake.cabeza.transform.x = snake.coord[0].first;
	snake.cabeza.transform.y = snake.coord[0].second;*/
}
void GameScene::Draw(void) {
	fondo.Draw();
	for (int i = 0; i < numC; i++) {
		for (int j = 0; j < 20; ++j) {
			tabla[i][j].Draw();
		}
	}
	//cabeza.Draw();
	//LA LINEA CABEZA.DRAW ES LA QUE PROVOCA TODOS LOS PROBLEMAS DE HAMBRE DEL MUNDO


	manzana.Draw();
	//pared.Draw();
}
