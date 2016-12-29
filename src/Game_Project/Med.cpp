#include "Med.h"
#include "Niveles.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


Med::Med() { //constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	cap = { { 100, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_08 };
	cua = { { cap.transform.x - 55, 130, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_10 };
	apple = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_11 };
	pared = { { 50, 100, W.GetWidth() / 12, W.GetHeight() / 12 }, ObjectID::S_12 };
}
Med::~Med() {
}
void Med::OnEntry(void) {
}
void Med::OnExit(void) {
}
void Med::Update(void) {
	

}
void Med::Draw(void) { //metodo que printea los sprites
	fondo.Draw();
	cap.Draw();
	cua.Draw();
	apple.Draw();
	pared.Draw();

}