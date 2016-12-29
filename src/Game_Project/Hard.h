#pragma once
#include "Scene.h"
#include "Sprites.h"

class Hard : public Scene
{
public: //declaracion de cabeceras
	explicit Hard();
	~Hard() override;
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