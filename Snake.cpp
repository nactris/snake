#include "Snake.h"



SnakeBoard::SnakeBoard() {
	w = 100;
	h = 100;
	field.resize(w);
	for (uint32_t iw = 0; iw < w; iw++)
	{
		field[iw].resize(h);
		for (uint32_t ih = 0; ih < h; ih++)
		{
			field[iw][ih] = EMPTY;
		}
	}

	for (uint32_t i = 2; i < 7; i++)
	{
		field[i][4] = WALL;
	}

	for (uint32_t i = 3; i < 6; i++)
	{
		field[7][i] = WALL;
	}
	field[1][1] = WALL;


	snake = Snake();
	snake.lenght = 5;
	snake.chunks.resize(5);
	for (size_t i = 0; i < 5; i++)
	{
		snake.chunks.at(i).x = 2 + i;
		snake.chunks.at(i).y = 8;
	}
	snake.chunks.at(0).type = BODY;
}
