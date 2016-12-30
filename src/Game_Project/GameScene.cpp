#include "GameScene.h"

using namespace Logger;
  


GameScene::GameScene() { //constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
//	manzana = Apple::Apple(this);
	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	life = 3;
	numC = xmlValues[0];
	numR = xmlValues[0];
	//num cols y num rows habra q leerlo desde el xml
	//numC = lvl.GetValue("Columns");//Niveles::getValue("z");
	//numC = numR = xmlValues[0];
	

	//Println(numC);
	//numR = numC;//Niveles::getValue("c");
	/*tabla = new Sprite*[numR];
	for (int i = 0; i < numR; i++) tabla[i] = new Sprite[numC];//por cada numero de filas se añaden el numero de columnas
	
	for (int i = 0; i < numR; i++) {
		for (int j = 0; j < numC; j++) {
			tabla[i][0].transform =		 { i * (20) + ((W.GetWidth()/2 - ((numR/2)*20))), 
										   ((W.GetHeight() / 2 - ((numC/2) * 20))),50, 50 };
			tabla[i][numC-1].transform = { i * (20) + ((W.GetWidth()/ 2 - ((numR/2) * 20))),
										   (numC-1) * (20) + ((W.GetHeight()/2 - ((numC/2)*20))),50, 50 };
			tabla[0][j].transform =		 { 0 + ((W.GetWidth() / 2 - ((numR/2) * 20))) ,
										   j * (20) + ((W.GetHeight() / 2 - ((numC/2) * 20))),50, 50 };
			tabla[numR-1][j].transform = { (numR-1) * (20) + ((W.GetWidth() / 2 - ((numR/2) * 20))),
										   j * (20) + ((W.GetHeight() / 2 - ((numC/2) * 20))),50, 50 };
			tabla[i][j].objectID = ObjectID::S_11;
		}
	}	*/
}
GameScene::~GameScene() {
}
void GameScene::OnEntry(void) {

}
void GameScene::OnExit(void) {
}
/*void GameScene::Apple() {
	srand(time(NULL));
	//A = { { 500, 200, W.GetWidth() / 20, W.GetHeight() / 20 }, ObjectID::S_10 };
	//numapple habra q leerlo desde xml
	numapple = 3;
	for (int i = 0; i < numapple; i++) {
		A = { { rand() % 100, rand() % tabla[0][i].transform.y, W.GetWidth() / 20, W.GetHeight() / 20 }, ObjectID::S_10 };
		apple.push_back(A);
	}
}*/
void GameScene::Xoc() {
	if ((snake.anim[0].transform.x >= grid.sprites[0][0].transform.x && snake.anim[0].transform.x <= grid.sprites[0][numC - 1].transform.x &&
	snake.anim[0].transform.y <= grid.sprites[0][0].transform.y || snake.anim[0].transform.y >= grid.sprites[0][numC - 1].transform.y) ||
	(snake.anim[0].transform.x <= grid.sprites[0][0].transform.x || snake.anim[0].transform.x >= grid.sprites[0][numC - 1].transform.x &&
	snake.anim[0].transform.y <= grid.sprites[0][0].transform.y && snake.anim[0].transform.y >= grid.sprites[0][numC - 1].transform.y) ||
	(snake.anim[0].transform.x >= grid.sprites[numR - 1][0].transform.x && snake.anim[0].transform.y >= grid.sprites[0][0].transform.y
	&& snake.anim[0].transform.y <= grid.sprites[0][numC - 1].transform.y) || (snake.anim[0].transform.x >= grid.sprites[0][0].transform.x
	&& snake.anim[0].transform.x <= grid.sprites[numR - 1][0].transform.x && snake.anim[0].transform.y <= grid.sprites[0][0].transform.y))
	{
	life -= 1;
	if (life == 0)
	snake.anim[0].transform.x = W.GetWidth() / 2;
	snake.anim[0].transform.y = W.GetHeight() / 2;
	snake.dir = 0;
	snake.anim.erase(snake.anim.begin() + 3, snake.anim.end());
	//	SM.SetCurScene<GameOver>();
	//Println("xoc");
	}


	/*if ((snake.anim[0].transform.x >= tabla[0][0].transform.x && snake.anim[0].transform.x <= tabla[0][numC - 1].transform.x &&
		snake.anim[0].transform.y <= tabla[0][0].transform.y || snake.anim[0].transform.y >= tabla[0][numC - 1].transform.y) ||
		(snake.anim[0].transform.x <= tabla[0][0].transform.x || snake.anim[0].transform.x >= tabla[0][numC - 1].transform.x &&
			snake.anim[0].transform.y <= tabla[0][0].transform.y && snake.anim[0].transform.y >= tabla[0][numC - 1].transform.y) ||
			(snake.anim[0].transform.x >= tabla[numR - 1][0].transform.x && snake.anim[0].transform.y >= tabla[0][0].transform.y
				&& snake.anim[0].transform.y <= tabla[0][numC - 1].transform.y) || (snake.anim[0].transform.x >= tabla[0][0].transform.x
					&& snake.anim[0].transform.x <= tabla[numR - 1][0].transform.x && snake.anim[0].transform.y <= tabla[0][0].transform.y))
	{
		life -= 1;
		if (life == 0) 
		snake.anim[0].transform.x = W.GetWidth() / 2;
		snake.anim[0].transform.y = W.GetHeight() / 2;
		snake.dir = 0;
		snake.anim.erase(snake.anim.begin() + 3, snake.anim.end());
	//	SM.SetCurScene<GameOver>();
		//Println("xoc");
	}*/
	/*for(int i =0; i< apple.size()-1; i++){
		if (snake.anim[0].transform.x > (apple[i].transform.x - apple[i].transform.w) && snake.anim[0].transform.x < (apple[i].transform.x + apple[i].transform.w) &&
			snake.anim[0].transform.y >(apple[i].transform.y - apple[i].transform.h) && snake.anim[0].transform.y < (apple[i].transform.y + apple[i].transform.h)) {
			apple.pop_back();
			snake.anim.push_back(snake.body);
		}//snake.anim.push_back(snake.Mov());
	}*/

}

void GameScene::Update(void) {
	grid.crearTabla(numR, numC);
	manzana.InitialPos(grid);

		Xoc();
		snake.Update();
}
void GameScene::Draw(void) {
	fondo.Draw();
//	for (int i = 0; i < apple.size() - 1; i++) {
	//	apple[i].Draw();
	//}
	/*for (int i = 0; i < numR; i++) {
		for (int j = 0; j < numC; j++) {
			tabla[i][j].Draw();
		}
	}*/
	grid.Draw();
	snake.Draw();
	manzana.Draw();
}