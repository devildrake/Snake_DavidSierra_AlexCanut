/*
#include <ctime>
#include "Grid.h"
#include "Window.h"
#include "IOManager.h"
#include "TimeManager.h"

Grid::Grid(std::string &&filename, int cellWidth, int cellHeight) {
	//auto lvlData(IOManager::LoadLevel(std::move(filename), m_rows, m_cols));
	//cellData = new Cell*[m_rows];
	//for (int i = 0; i < m_rows; ++i) cellData[i] = new Cell[m_cols];
	//srand(unsigned(time(nullptr)));
	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_cols; ++j) {
			cellData[0][j].objectID = ObjectID::S_12;
			cellData[m_rows][j].objectID = ObjectID::S_12;
			cellData[i][0].objectID = ObjectID::S_12;
			cellData[i][m_cols].objectID = ObjectID::S_12;
			cellData[i][j].transform = { j * (cellWidth + 2) + ((W.GetWidth() - cellWidth*m_cols) >> 1),
				i * (cellHeight + 2) + ((W.GetHeight() - cellHeight*m_rows) >> 1),
				cellWidth, cellHeight };
			cellData[i][j].objectID = ObjectID::S_12;
			CandyTransform(i, j) = cellData[i][j].transform;
			//CandyID(i, j) = lvlData[i][j];
		}
	}
	//gridState = GridState::LINE_CHECKING;
}*/