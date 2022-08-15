#ifndef _SNAKE_H
#define _SNAKE_H
#include "Field.h"

const int MAX_LEN = 10;


struct sElement {
	int left;
	int top;
	int right;
	int bottom;

};
struct Snake {
	int arr[MAX_LEN];
	sElement snake;
	int len;

};

void create_snake(fElement& sqs, int i_x, int i_y, int len, int i);
void draw_snake(Snake& sn);

#endif;

