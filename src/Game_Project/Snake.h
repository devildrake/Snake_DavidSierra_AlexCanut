#pragma once
#include <vector>
#include "Sprites.h"
using namespace std;

class Snake{
public:
	vector<Sprite> conjuntoSerp;

    Snake();
	void Mov();//Función que detecta las inputs 

	void Update(void); 

	void Draw(void);

	void AñadirTrozo();
	void ChangeLast();

	int dir = 0; //Integer en función del cual se varia la direccion de la serpiente

	int iPosX; //Posicion inicial X de la cabeza dentro de la tabla

	int iPosY;//Posicion inicial  Y de la cabeza dentro de la tabla

	int tamaño; //Tamaño del Vector de sprites

	bool isBlocked; //Flag para que no se le puedan dar mas de una orden a la vez,
	//haciendo bypass a la prohibicion de cambio de rumbo de izquierda a derecha
	//sin pasar por arriba o abajo

	bool isAlive;

	bool hasMoved; //Flag para que el GameScene.cpp sepa cuando la serpiente se ha movido


	int posX; //Posicion X de la serpiente en la tabla
	int posY; //Posicion Y de la serpiente en la tabla

	int prevPosX; //Previa posicion X de la serpiente en la tabla
	int prevPosY; //Previa posicion Y de la serpiente en la tabla

	Uint64 timer; //Timer que marca el tiempo hasta el siguiente movimiento
	Uint64 prevTime; //contador del tiempo anterior para hacer comparaciones

	Sprite head;
	Sprite body;
	Sprite tail;

private:
};