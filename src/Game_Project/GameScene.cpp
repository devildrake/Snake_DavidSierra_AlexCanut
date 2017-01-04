#include "GameScene.h"

using namespace Logger;
  
GameScene::GameScene() { //constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
//	manzana = Apple::Apple(this);
	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	life = 3;
	hasStarted = 0;
	c = 0;
	GameScene::unaManzana.objectID = ObjectID::S_10;
	/*numC = xmlValues[0]; //Aqui es donde supuestamente encuentra un valor de vector out of bounds
	numR = xmlValues[0];*/

	//num cols y num rows habra q leerlo desde el xml
	//numC = lvl.GetValue("Columns");//Niveles::getValue("z");


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

void GameScene::CheckManzana() {
	if (snake.head.transform.x == manzana.laManzana.transform.x+manzana.laManzana.transform.w) {
		std::cout << "MISMA X JODER SI SISISISISI  " << std::endl;
	}
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
void GameScene::CheckHit() {
	//Al hacer este If Explota todo joder
	if ((snake.conjuntoSerp[0].transform.x >= grid.sprites[0][0].transform.x && snake.conjuntoSerp[0].transform.x <= grid.sprites[0][numC - 1].transform.x
	&& snake.conjuntoSerp[0].transform.y <= grid.sprites[0][0].transform.y
	|| snake.conjuntoSerp[0].transform.y >= grid.sprites[0][numC - 1].transform.y)
	||(snake.conjuntoSerp[0].transform.x <= grid.sprites[0][0].transform.x
	|| snake.conjuntoSerp[0].transform.x >= grid.sprites[0][numC - 1].transform.x && snake.conjuntoSerp[0].transform.y <= grid.sprites[0][0].transform.y
	&& snake.conjuntoSerp[0].transform.y >= grid.sprites[0][numC - 1].transform.y)
	||(snake.conjuntoSerp[0].transform.x >= grid.sprites[numR - 1][0].transform.x && snake.conjuntoSerp[0].transform.y >= grid.sprites[0][0].transform.y
	&& snake.conjuntoSerp[0].transform.y <= grid.sprites[0][numC - 1].transform.y)
	|| (snake.conjuntoSerp[0].transform.x >= grid.sprites[0][0].transform.x &&
		snake.conjuntoSerp[0].transform.x <= grid.sprites[numR - 1][0].transform.x &&
		snake.conjuntoSerp[0].transform.y <= grid.sprites[0][0].transform.y))
	{
	life -= 1;
	if (life == 0)
	snake.conjuntoSerp[0].transform.x = W.GetWidth() / 2;
	snake.conjuntoSerp[0].transform.y = W.GetHeight() / 2;
	snake.dir = 0;
	snake.conjuntoSerp.erase(snake.conjuntoSerp.begin() + 3, snake.conjuntoSerp.end());
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

	//std::cout << "VALOR XML DE MIERDA JODER " << Niveles::GetValue("Columns") << std::endl;
	c++;
	std::cout <<"Time nº" << TM.GetCurTime() << endl;

	if (!hasStarted) {
		numC = 5;
		numR = 5;

		numC *= Niveles::GetValue("Columns");
		numR *= Niveles::GetValue("Columns");
		grid.crearTabla(numC,numR);
		cout << "TablaCol " << grid.numC << endl;
		//manzana.InitialPos(grid);
		//manzana.SetPos(grid);
		//manzana.AumentarVector(1);
		//ChangeManPos();
		//manzana.SetPos(numC,numR);
		manzana.laManzana.transform.x = W.GetWidth() / 2;
		manzana.laManzana.transform.y = W.GetHeight() / 2;
		tempT = &grid;
		manzana.SetPos(tempT);

		cout << "POSMANZANA_X" << unaManzana.transform.x<<endl;

		
		snake.iPosX = round(numC / 2);
		snake.iPosY = round(numR / 2);

		
		SnakeSpawn();

		hasStarted = true;

	}
	//manzana.InitialPos(grid);
	//	CheckHit();
		CheckManzana();
		snake.Update();
		
		if (snake.dir != 0) {
			ActualizarSnake();
			snake.ChangeLast();
		}
}

void GameScene::SnakeSpawn() {

	snake.posX = snake.iPosX;
	snake.posY = snake.iPosY;

	snake.conjuntoSerp[0].transform.x = grid.sprites[snake.iPosX][snake.iPosY].transform.x;
	snake.conjuntoSerp[0].transform.y = grid.sprites[snake.iPosX][snake.iPosY].transform.y;
	
	snake.conjuntoSerp[1].transform.x = snake.conjuntoSerp[0].transform.x;
	snake.conjuntoSerp[1].transform.y = grid.sprites[snake.iPosX][snake.iPosY-1].transform.y;

	snake.conjuntoSerp[2].transform.x = snake.conjuntoSerp[0].transform.x;
	snake.conjuntoSerp[2].transform.y = grid.sprites[snake.iPosX][snake.iPosY - 2].transform.y;

	//snake.head.transform.x = grid.sprites[snake.iPosX][snake.iPosY].transform.x;
	//snake.head.transform.y = grid.sprites[snake.iPosX][snake.iPosY].transform.y;

	cout << "PosicionInicialSerpiente = " << snake.conjuntoSerp[0].transform.x << ", " << snake.conjuntoSerp[0].transform.y << endl;
}

void GameScene::ActualizarSnake() {

	snake.conjuntoSerp[0].transform.x = grid.sprites[snake.posX][0].transform.x;
	snake.conjuntoSerp[0].transform.y = grid.sprites[0][snake.posY].transform.y;

	
	snake.conjuntoSerp[snake.tamaño - 1].transform.x = grid.sprites[snake.prevPosX][0].transform.x;
	snake.conjuntoSerp[snake.tamaño - 1].transform.y = grid.sprites[0][snake.prevPosY].transform.y;



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
	manzana.Draw();
	snake.Draw();
	
	//unaManzana.Draw();
}