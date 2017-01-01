#include "Niveles.h"
#include "GameScene.h"
#include "ID.h"
#include "XML.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include <XML/rapidxml_utils.hpp>
using namespace Logger;

static vector <int> xmlVal;

Niveles::Niveles() {//constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_00 };
	title = { { 250, 0, W.GetWidth() / 2, W.GetHeight() / 2 }, ObjectID::S_01 };
	easy = { { 400,300,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_03 };
	med = { { 400,400,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_04 };
	hard = { { 400,500,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID::S_05 };


//	cout<<"notOutOfRange " << xmlVal[0];

}
Niveles::~Niveles() { //destructor
}
int Niveles::GetValue(std::string valor) {
	if (xmlVal.size() > 0) {
		if (valor == "Columns") return xmlVal[0];
		else if (valor == "Grid") return xmlVal[1];
		else if (valor == "Time") return xmlVal[2];
		else if (valor == "V") return xmlVal[3];
		else if (valor == "Food") return xmlVal[4];
		else if (valor == "IncrementoFood") return xmlVal[5];
		else return NULL;
	}
	else return NULL;
}
void Niveles::OnEntry(void) { 
}
void Niveles::OnExit(void) {
}
void Niveles::Update(void) {
	static MouseCoords mouseCoords(0, 0); //variable q recoje la coordenadas del puntero del mouse al darle click
	
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) { //si hace click izquierdo con el raton
		mouseCoords = IM.GetMouseCoords(); //coge esascordenadas y las parintea en consola
		//Println(mouseCoords);
		
		if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 360 && mouseCoords.y <= 400)) { //si el click del raton essta entre esascoordenadas, entra en la escena que contiene el nivel Easy y carga su XML
			XML("easy");
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>();					//el if lo modificaremos para hacerlo sin coordenadas y usar la width i height del sprite (coord x = -width/2, coord y = -heigth/2)
			//setAttrValue("easy", "v", 1995);
			//cout << "Valor de v: " << getAttrValue("v") << endl;
		}
		else if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 460 && mouseCoords.y <= 500)) {//si el click del raton essta entre esascoordenadas, entra en la escena que contiene el nivel Medium y carga su XML
			XML("medium");
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>();
			
		}
		else if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 560 && mouseCoords.y <= 600)) {//si el click del raton essta entre esascoordenadas, entra en la escena que contiene el nivel Hard y carga su XML
			XML("hard");
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>();
			
		}
	}

}
void Niveles::Draw(void) {
	background.Draw();
	title.Draw();
	easy.Draw();
	med.Draw();
	hard.Draw();
}

