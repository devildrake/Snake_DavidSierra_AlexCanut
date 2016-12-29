#pragma once
#include "Scene.h"
#include "Sprites.h"
#include <fstream>
#include <stdio.h>
#include <strstream>
#include <XML/rapidxml_utils.hpp>

class Easy : public Scene
{
public: //declaracion de cabeceras
	explicit Easy();
	~Easy() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
	
private:
	Sprite fondo;
	Sprite cap;
	Sprite cua;
	Sprite apple;
	Sprite pared;
	

};