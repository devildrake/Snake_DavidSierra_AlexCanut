#pragma once
#pragma once
#include "Scene.h"
#include "Sprites.h"
#include "Snake.h"
#include "Apple.h"
#include <fstream>
#include <stdio.h>
#include <strstream>
#include "Niveles.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include <time.h>
#include "XML.h"
#include <math.h>

class GameScene : public Scene
{
public: //declaracion de cabeceras
	int c;

	static int columnaFila;
	explicit GameScene();
	~GameScene() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
	void CheckHit();
	void GameScene::ActualizarSnake();
	void CheckManzana();
	void GameScene::SnakeSpawn();

	int numapple;
	bool hasStarted;
	//Sprite **tabla;
	int numC = 30;
	int numR = 30;
	Sprite unaManzana;
	void ChangeManPos(void);
	Tabla* tempT;
private:
	Tabla grid;
	Sprite fondo;
	Sprite pared;
	Snake snake;
	Sprite manzana;
	Sprite prueba;
	int life;

	int posAY;
	int posAX;

};