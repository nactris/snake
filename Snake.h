#pragma once

#include <vector>
#include <array>

enum Field : uint8_t { EMPTY = 0, WALL, FOOD };
enum SnakeChunkType : uint8_t { HEAD = 0, BODY };enum SnakeDirection : uint8_t { UP = 0, DOWN, LEFT,RIGHT };struct SnakeChunk {
	uint32_t x, y;
	SnakeChunkType type = BODY;
};struct Snake
{	uint8_t lenght;
	SnakeDirection dir;	std::vector<SnakeChunk> chunks;};class SnakeBoard {
private:
	uint32_t w,h;
	Snake snake;

	std::vector<std::vector<Field>> field;

public:
	SnakeBoard();

};



