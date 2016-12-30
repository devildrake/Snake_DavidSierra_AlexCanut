#pragma once
#include "Scene.h"
#include "Sprites.h"
#include <vector>

class Niveles : public Scene //clase para controlar lasescenas de losdistintos niveles del juego
{
public:
	//declaracion de los cabezales de los distintos metodos y variables que se usaran en el cpp
	explicit Niveles(); 
	~Niveles() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
	int static GetValue(std::string valor);


	//static vector<int> xmlValues;
private:
	Sprite background;
	Sprite title;
	Sprite easy;
	Sprite med;
	Sprite hard;
	//vector <int> xmlVal;


};