#pragma once

#include <vector>
#include <array>
#include <random>

enum Field : uint8_t { EMPTY = 0, WALL, FOOD, SNAKE_HEAD, SNAKE_BODY };
enum State : uint8_t { STOP = 0, RUN, END };
enum Mode : uint8_t { DEBUG = 0, EASY, MEDIUM, HARD};
enum SnakeChunkType : uint8_t { HEAD = 0, BODY };enum SnakeDirection : uint8_t { UP = 0, DOWN, LEFT,RIGHT };const char symbol[] = { ' ','#','$' ,'H' ,'B' };uint32_t rnd(uint32_t min, uint32_t max);struct SnakeChunk {
	uint32_t x, y;
	SnakeChunkType type = BODY;
};struct Snake
{	uint8_t lenght;
	SnakeDirection dir;	std::vector<SnakeChunk> chunks;};class SnakeBoard {
private:
	State state = STOP;
	Mode mode;
	uint32_t w,h;
	Snake snake;
	std::vector<std::vector<Field>> boardView;
	std::vector<std::vector<Field>> field;

public:
	SnakeBoard();
	SnakeBoard(const uint32_t& width_, const uint32_t& height_, const Mode& mode_);
	void updateView();
	void display();

};



