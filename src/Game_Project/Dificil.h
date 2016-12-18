#pragma once
#include "Scene.h"
#include "Sprites.h"

class Dificil : public Scene
{
public:
	explicit Dificil();
	~Dificil() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:
	Sprite fondo;
	Sprite manzana;
	Sprite pared;

};