#include "Facil.h"
#include "LevelScene.h"
#include "Grid.h"
#include "ID.h"
#include "IOManager.h"
#include "Logger.h"
#include "SceneManager.h"

using namespace Logger;


Facil::Facil(){
	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	manzana = { {50, 100, W.GetWidth()/12, W.GetHeight()/12 }, ObjectID::S_11 };
	pared = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_12 };

}
Facil::~Facil() {
}
void Facil::OnEntry(void) {
}
void Facil::OnExit(void) {
}
void Facil::Update(void) {
	
}



void Facil::Draw(void) {
	fondo.Draw();
	manzana.Draw();
	pared.Draw();

}
