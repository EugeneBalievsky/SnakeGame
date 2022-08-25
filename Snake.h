#ifndef _SNAKE_H
#define _SNAKE_H
#include "Field.h"
#include<vector>

std::vector <std::pair <int, int>> create_snake(int b, int a, int m);

void draw_snake(std::vector<std::vector<field_element>>& v, int b, int a);

void draw_food(std::vector<std::vector<field_element>>& v, int b, int a);



#endif;

