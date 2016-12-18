#pragma once
#include "Scene.h"
#include "Snake.h"
#include "Sprites.h"
#include <fstream>
#include <stdio.h>
#include <strstream>
#include <XML/rapidxml_utils.hpp>

class GameScene : public Scene
{
public:
	explicit GameScene();
	~GameScene() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
	void NewFruit();

	void XML(std::string &&filename) {

		rapidxml::file<> xmlFile(RESOURCE_FILE(filename));
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());

		std::cout << "Dificultad nivel: " << doc.first_node()->first_node("easy")->name() << "\n";
	}

private:
	int numC;
	int numR;
	Sprite **tabla;
	Sprite fondo;
	Sprite manzana;
	Sprite pared;
	Snake snake;
	Sprite cabeza;
	Sprite cuerpo;
	Sprite cola;
};