#include "LevelScene.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include <XML/rapidxml_utils.hpp>
#include "GameScene.h"
using namespace Logger;

//esta clase es el nivel de seleccion de dificultad
LevelScene::LevelScene() {
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_00 };
	title = { { 250, 0, W.GetWidth() / 2, W.GetHeight() / 2 }, ObjectID::S_01 };
	easy = { { 400,300,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_03 };
	med = { { 400,400,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_04 };
	hard = { { 400,500,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID::S_05 };
}
LevelScene::~LevelScene() {
}
void LevelScene::OnEntry(void) {
}
void LevelScene::OnExit(void) {
}
void LevelScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		mouseCoords = IM.GetMouseCoords();
		if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 360 && mouseCoords.y <= 400)) {
			SM.SetCurScene<GameScene>(); 
		}
		else if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 460 && mouseCoords.y <= 500)) {
			SM.SetCurScene<GameScene>();
		}
		else if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 560 && mouseCoords.y <= 600)) {
			SM.SetCurScene<GameScene>();
		}
	}
}
void LevelScene::Draw(void) {
	background.Draw();
	title.Draw();
	easy.Draw();
	med.Draw();
	hard.Draw();
}