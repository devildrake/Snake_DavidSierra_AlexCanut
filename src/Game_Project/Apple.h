#include <vector>
#include "Sprites.h"
#include "Tabla.h"
using namespace std;

class Apple {
public:
	Sprite laManzana;
	Apple(void);
	~Apple();
	void Draw(void);
	void Update(Tabla);
	void SetPos(Tabla);
	void SetPos(Tabla, int, int);
	void InitialPos(Tabla);
	int posX;
	int posY;
	bool initialized;
private:

};

