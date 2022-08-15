#include "Field.h"
#include "Snake.h"
#include <iostream>
#include <string>
#include "include/graphics.h"

Snake sns[MAX_LEN];
 
void create_snake(fElement& sqs, int i_x, int i_y, int len, int i) {
	Snake sn;
	sn.snake.left = sqs[i_x][i_y].left;
	sn.snake.left = sqs[i_x][i_y].top;
	sn.snake.left = sqs[i_x][i_y].right;
	sn.snake.left = sqs[i_x][i_y].bottom;
	sn.len = len;
	sns[i] = sn;
}
void draw_snake(Snake& sn) {
	setfillstyle(SOLID_FILL, YELLOW);
	for (int i = 0; i < sn.len; ++i) {
		bar(sns[i].snake.left, sns[i].snake.top, sns[i].snake.right, sns[i].snake.bottom);
	}
}
