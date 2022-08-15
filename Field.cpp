#include "Field.h"
#include <iostream>
#include <string>
#include "include/graphics.h"

fElement sqs[MAX_Y][MAX_X];

void create_field(int left, int top, int right, int bottom, int x, int y) {
	fElement sq;
	sq.left = left;
	sq.top = top;
	sq.right = right;
	sq.bottom = bottom;
	sqs[y][x] = sq;
}
void draw_field() {
	setcolor(BLUE);
	for (int i = 0; i < MAX_Y; ++i) {
		for (int j = 0; j < MAX_X; ++j) {
			rectangle(sqs[i][j].left, sqs[i][j].top, sqs[i][j].right, sqs[i][j].bottom);
		}
	}
	setcolor(WHITE);
	rectangle(50, 50, 850, 850);
}
