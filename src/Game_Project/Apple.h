#include <vector>
#include "Sprites.h"
#include "GameScene.h"
using namespace std;

class Apple {
public:
	Sprite laManzana;
	Apple(GameScene*);
	Apple(void);
	~Apple();
	void Draw(void);
	void Update(void);
	void changePos(void);
	int posX;
	int posY;

private:

	GameScene* laScene;
};
*/
/*class Apple {
public:

	vector<Sprite> apple;
	Sprite** laTabla;
	Apple(int,int);
	Apple();
	~Apple();
	void Update(void);
	void Draw(void);
	void Pop();
	Sprite A;

private:
	 int numApple;
//	 GameScene laGameScene;
};