#include "Dificil.h"
#include "LevelScene.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


Dificil::Dificil() {
	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	manzana = { { 100, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_11 };
	pared = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_12 };;

}
Dificil::~Dificil() {
}
void Dificil::OnEntry(void) {
}
void Dificil::OnExit(void) {
}
void Dificil::Update(void) {
	
}
void Dificil::Draw(void) {
	fondo.Draw();
	manzana.Draw();
	pared.Draw();
}