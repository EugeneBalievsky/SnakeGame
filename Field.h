#ifndef _FIELD_H
#define _FIELD_H
#include<vector>

struct field_element {
    int left = left;
    int top = top;
    int right = right;
    int bottom = bottom;
};

std::vector<std::vector<field_element>> create_field();


void game_over();





#endif