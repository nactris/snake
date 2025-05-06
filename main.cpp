
#include <iostream>
#include "Snake.h"


SnakeBoard::SnakeBoard(const uint32_t& width_, const uint32_t& height_, const Mode& mode_) {	w = width_;
	h = height_;	mode = mode_;	field.resize(w);
	boardView.resize(w);	for (uint32_t iw = 0; iw < w; iw++)
	{
		field[iw].resize(h);
		boardView[iw].resize(h);
		for (uint32_t ih = 0; ih < h; ih++)
		{
			field[iw][ih] = EMPTY;
		}
	}	uint32_t wall_num = mode * 2;	uint32_t total_area = ceil((double)(w + h) *mode * 0.5);	uint32_t used_area = 0;	auto checkwall = [](SnakeBoard board, uint32_t x, uint32_t y) {		bool  walled =( board.field[x][y] == WALL);		if (x + 1 < board.w) walled |= board.field[x + 1][y] == WALL;		if (x - 1 > 0) walled |= board.field[x - 1][y] == WALL;		if (y + 1 > board.h) walled |= board.field[x][y + 1] == WALL;		if (y - 1 > 0) walled |= board.field[x][y - 1] == WALL;		return walled;	};	auto checkcollide = [](SnakeBoard board,bool vertical,uint32_t size, uint32_t x, uint32_t y) {		int  walled = -1;		//(board.field[x][y] == WALL);		for (size_t i = 0; i < size; i++)
		{
			if (vertical){
				if (board.field[x][y + i] == WALL) return i;
			}
			else {
				if (board.field[x + i][y ] == WALL) return i;

			}
			 
		}	};	for (size_t i = 0; i < wall_num; i++)
	{
		bool vertical = rnd(0, 1);

		uint32_t lenght = (total_area - used_area);
		if (wall_num - 1 != i) { lenght = rnd(2, std::min( vertical ? h : w,total_area - ((wall_num - i - 1) * 2) - used_area)); }
		used_area += lenght;
	}}


int main()
{
	SnakeBoard board = SnakeBoard(10,10,MEDIUM);
	//board.updateView();
	board.display();
}
