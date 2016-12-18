#include "MainMenu.h"
#include "LevelScene.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


MainMenu::MainMenu() {
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_00 };
	title = { { 250, 0, W.GetWidth()/2, W.GetHeight()/2 }, ObjectID::S_01 };
	/*play = { { 362, 350, W.GetWidth()/3, W.GetHeight()/3 }, ObjectID::S_02 };
	exit = { { 362,550,W.GetWidth()/3, W.GetHeight()/3 }, ObjectID::S_06 };*/
	play = { { playPosX, playPosY, W.GetWidth() / 3, W.GetHeight() / 3 }, ObjectID::S_02 };
	exit = { { ExitPosX,ExitPosY,W.GetWidth() / 3, W.GetHeight() / 3 }, ObjectID::S_06 };
	
}
MainMenu::~MainMenu() {
}
void MainMenu::OnEntry(void) {
}
void MainMenu::OnExit(void) {
}
void MainMenu::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		mouseCoords = IM.GetMouseCoords();
		if ((mouseCoords.x >= playPosX+63 && mouseCoords.x <= playPosX+253) && (mouseCoords.y >= playPosY+80 && mouseCoords.y <= playPosY+140)) {		
			SM.SetCurScene<LevelScene>();
		}
		else if ((mouseCoords.x >= ExitPosX+63 && mouseCoords.x <= ExitPosX+253) && (mouseCoords.y >= ExitPosY+80 && mouseCoords.y <= ExitPosY+140)) {
			SetState<SceneState::EXIT>();
		}
	}

}
void MainMenu::Draw(void) {
	background.Draw();
	title.Draw();
	play.Draw();
	exit.Draw();

}