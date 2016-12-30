#pragma once
#pragma once
#include "Scene.h"
#include "Sprites.h"
#include "Snake.h"
#include "Apple.h"
#include <fstream>
#include <stdio.h>
#include <strstream>


class GameScene : public Scene
{
public: //declaracion de cabeceras
	explicit GameScene();
	~GameScene() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Xoc();
	int numapple;
	//Sprite **tabla;
	int numC = 30;
	int numR = 30;
	
private:
	Tabla grid;
	Sprite fondo;
	Sprite pared;
	Snake snake;
	Apple manzana;
	int life;
};