#include "Snake.h"
#include<iostream>
#include <cmath>


uint32_t rnd(uint32_t min, uint32_t max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint32_t> distrib(min, max);
	return distrib(gen);}


SnakeBoard::SnakeBoard() {
	mode = MEDIUM;
	state = STOP;
	w = 10;
	h = 10;
	field.resize(w);
	boardView.resize(w);
	for (uint32_t iw = 0; iw < w; iw++)
	{
		field[iw].resize(h);
		boardView[iw].resize(h);
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
	field[1][1] = FOOD;


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



void SnakeBoard::display() {
	std::cout << "   ";

	for (size_t iw = 0; iw < w; iw++)
	{
		std::cout << " " << iw << " ";
	}
	std::cout << std::endl;

	for (size_t ih = 0; ih < h; ih++)
	{
		std::cout << " "<<ih<<" ";
		for (size_t iw = 0; iw < w; iw++)
		{
			std::cout << "[" << symbol[boardView[iw][ih]] << "]";



		}
		std::cout << std::endl;

	}

}

void SnakeBoard::updateView() {

	for (size_t ih = 0; ih < h; ih++)
	{
		for (size_t iw = 0; iw < w; iw++)
		{
			boardView[iw][ih] = field[iw][ih];

		}

	}

	for (size_t i = 1; i < snake.lenght; i++)
	{
		boardView[snake.chunks[i].x][snake.chunks[i].y] = SNAKE_BODY;
	}
	boardView[snake.chunks[0].x][snake.chunks[0].y] = SNAKE_HEAD;


}
