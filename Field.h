#ifndef _FIELD_H
#define _FIELD_H

const int MAX_X = 50;
const int MAX_Y = 50;


struct fElement {
	int left;
	int top;
	int right;
	int bottom;
	
};

void create_field(int left, int top, int right, int bottom, int x, int y);
void draw_field();





#endif