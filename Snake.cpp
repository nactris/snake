#include "Snake.h"

SnakeBoard::SnakeBoard(uint32_t width, uint32_t height) {
		w = width;
		h = height;
		field.resize(w);
		for (uint32_t iw = 0; iw < width; iw++)
		{
			field[iw].resize(height)
			for (uint32_t ih = 0; ih < height; ih++)
			{
				field[iw][ih] = EMPTY;
			}
		}
	}
};

