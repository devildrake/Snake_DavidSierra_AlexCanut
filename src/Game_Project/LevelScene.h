#pragma once
#include "Scene.h"
#include "Sprites.h"

class LevelScene : public Scene
{
public:
	explicit LevelScene();
	~LevelScene() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:
	Sprite background;
	Sprite title;
	Sprite easy;
	Sprite med;
	Sprite hard;


};