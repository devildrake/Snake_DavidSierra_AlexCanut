#include "Tabla.h"

Tabla::Tabla() {
	wasMade = false;
	numC = 0;
	numR = 0;
}

Tabla::~Tabla() {
	delete(sprites);
}

void Tabla::Draw() {
	for (int i = 0; i < numR; i++) {
		for (int j = 0; j < numC; j++) {
			sprites[i][j].Draw();
		}
	}
}

void Tabla::crearTabla(int AnumR, int AnumC) {
	if (!wasMade) {

		numC = AnumC;
		numR = AnumR;

		//sprites = new Sprite*();

		sprites = new Sprite*[numR];

		for (int i = 0; i < numR; i++) sprites[i] = new Sprite[numC];//por cada numero de filas se añaden el numero de columnas
		
		std::cout << "CREA TABLA" << std::endl;

		/*for (int i = 0; i < numR; i++) {
			for (int j = 0; j < numC; j++) {
				sprites[i][0].transform = { i * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
					((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
				sprites[i][numC - 1].transform = { i * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
					(numC - 1) * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
				sprites[0][j].transform = { 0 + ((W.GetWidth() / 2 - ((numR / 2) * 20))) ,
					j * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
				sprites[numR - 1][j].transform = { (numR - 1) * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
					j * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
				sprites[i][j].objectID = ObjectID::S_11;
				//std::cout <<"Se ha creado un sprite con posicion: X--> "<< sprites[i][j].transform.x<<"  Y--> "<< sprites[i][j].transform.y << "i-->  "<<i<< " j--> "<< j <<"\n";
				


			
			}
		}*/
		
		int x = 0;
		for (int i = 0; i < numR; i++) {
			int y = 0;
			for (int j = 0; j < numC; j++) {
				
				sprites[i][j].transform.x = x;

				sprites[i][j].transform.y = y;

				sprites[i][j].transform.w = 20;
				sprites[i][j].transform.h = 20;

				if (i == 0 || j == 0||i==numR-1||j==numC-1) {
					sprites[i][j].objectID = ObjectID::S_11;
				}
				else {
					sprites[i][j].objectID = ObjectID::S_12;
				}
				//std::cout <<"Se ha creado un sprite con posicion: X--> "<< sprites[i][j].transform.x<<"  Y--> "<< sprites[i][j].transform.y << "i-->  "<<i<< " j--> "<< j <<"\n";
				
				
				
				y += 20;
			}
			x += 20;
		}

		
		wasMade = true;
		std::cout << "YA SE HA CREADO LA TABLA" << std::endl;
	}
}

