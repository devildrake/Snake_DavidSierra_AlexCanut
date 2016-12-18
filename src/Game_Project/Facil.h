#pragma once
#include "Scene.h"
#include "Sprites.h"
#include <fstream>
#include <stdio.h>
#include <strstream>
#include <XML/rapidxml_utils.hpp>

class Facil : public Scene
{
public:
	explicit Facil();
	~Facil() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
	void XML(std::string &&filename) {

		rapidxml::file<> xmlFile(RESOURCE_FILE(filename));
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());

		std::cout << "Dificultad nivel: " << doc.first_node()->first_node("easy")->name() << "\n";
	}

private:
	Sprite fondo;
//	Grid g_facil;
	Sprite manzana;
	Sprite pared;
};