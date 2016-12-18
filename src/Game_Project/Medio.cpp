#include "Medio.h"
#include "LevelScene.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


Medio::Medio() {
	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	manzana = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_11 };
	pared = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_12 };
}
Medio::~Medio() {
}
void Medio::OnEntry(void) {
}
void Medio::OnExit(void) {
}
void Medio::Update(void) {
	

}
void Medio::Draw(void) {
	fondo.Draw();
	pared.Draw();
	manzana.Draw();
	
}