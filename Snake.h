#pragma once

#include <vector>
#include <array>

enum Field : uint8_t { EMPTY = 0, WALL, FOOD };
enum SnakeChunkType : uint8_t { HEAD = 0, BODY };enum SnakeDirection : uint8_t { UP = 0, DOWN, LEFT,RIGHT };struct SnakeChunk {
	uint32_t x,y;
	SnakeChunkType type;
};
class SnakeBoard {
	uint32_t w,h;
	struct Snake 
	{		SnakeDirection dir;		std::vector<SnakeChunk> chunks;	} snake;
	std::vector<std::vector<Field>> field;

public:
	SnakeBoard(uint32_t width, uint32_t height);

};



