#include "Hard.h"
#include "Niveles.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


Hard::Hard() { //constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	cap = { { 100, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_08 };
	cua = { { cap.transform.x - 55, 130, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_10 };
	apple = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_11 };
	pared = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_12 };;

}
Hard::~Hard() {
}
void Hard::OnEntry(void) {
}
void Hard::OnExit(void) {
}
void Hard::Update(void) {
	
}
void Hard::Draw(void) { //metodo que pinta los sprites
	fondo.Draw();
	cap.Draw();
	cua.Draw();
	apple.Draw();
	pared.Draw();
}