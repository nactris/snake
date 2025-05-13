
#include <iostream>
#include "Snake.h"



SnakeBoard::SnakeBoard(const uint32_t& width_, const uint32_t& height_, const Mode& mode_) {
	w = width_;
	h = height_;
	mode = mode_;
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


	uint32_t wall_num = mode * 2;
	uint32_t total_area = ceil((double)(w + h) *mode * 0.5);
	uint32_t used_area = 0;
	std::cout << "total wall area:" << total_area << std::endl;
	auto checkwall = [](SnakeBoard &board, uint32_t x, uint32_t y) {
		bool  walled = (board.field[x][y] == WALL);

		if (x + 1 < board.w) walled |= board.field[x + 1][y] == WALL;
		if (x - 1 > 0) walled |= board.field[x - 1][y] == WALL;
		if (y + 1 > board.h) walled |= board.field[x][y + 1] == WALL;
		if (y - 1 > 0) walled |= board.field[x][y - 1] == WALL;

		return walled;
	};


	if (mode == DEBUG)	{
		for (size_t i = 0; i < std::min(w,h); i++)
		{
			field[i][i] = WALL;
			boardView[i][i] = WALL;
		}
	}
	else
	{
	for (size_t wall_iter = 0; wall_iter < wall_num; wall_iter++)
	{
		bool vertical = rnd(0, 1);

		uint32_t lenght = (total_area - used_area);
		uint32_t max_wall_lenght = std::min((int32_t)(vertical ? h - 3 : w - 3), (int32_t)(total_area - used_area - (wall_num - wall_iter - 1) * 2));
		uint32_t min_wall_lenght = std::min((int32_t)max_wall_lenght, std::max(2, (int32_t)(total_area - used_area - (wall_num - wall_iter - 1) * 7)));
		if (wall_num - 1 != wall_iter) { lenght = rnd(min_wall_lenght, max_wall_lenght); }
		std::cout << max_wall_lenght << " max, " << min_wall_lenght << " min( " << (int32_t)(total_area - used_area - (wall_num - wall_iter - 1) * 7) << ") got " << lenght << std::endl;

		int wx = rnd(0, w - 1 - (1 - vertical)*lenght);
		int wy = rnd(0, h - 1 - vertical * lenght);

		int hits = 0;
		bool gap = false;
		//std::cout << wx << " " << wy << " " << lenght << " " << vertical << std::endl;
		uint32_t tx = wx;
		uint32_t ty = wy;
		for (size_t i = 0; i < lenght; i++)
		{
			if (field[tx][ty] == WALL) {
				std::cout << " HIT " << std::endl;
				hits++;

			}

			if (vertical) {
				ty++;
			}
			else {
				tx++;
			}

		}
		std::cout << wall_iter << " done! " << hits << " hits!" << std::endl;

		tx = wx;
		ty = wy;
		if (hits < 1) {
			used_area += lenght;
			std::cout << wall_iter << " filling... " << std::endl;

			for (size_t i = 0; i < lenght; i++)
			{
				field[tx][ty] = WALL;
				boardView[tx][ty] = WALL;
				if (vertical) {
					ty++;
				}
				else {
					tx++;
				}

			}

		}
		else
		{
			wall_iter--;

		}


	}
	}



}


int main()
{
	SnakeBoard board = SnakeBoard(10,15,DEBUG);
	//board.updateView();
	board.display();
}
