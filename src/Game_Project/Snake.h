#pragma once
#include "Scene.h"
#include <vector>
#include "Sprites.h"
using namespace std;
class Snake : public Scene
{
public:
	explicit Snake();
	~Snake() override;
	void Draw(void) override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;

private:

	vector<Sprite> cachoSerp;

	int vel;

};