#include "Field.h"
#include "Snake.h"
#include <iostream>
#include <string>
#include "include/graphics.h"

std::vector <std::pair <int, int>> create_snake(int b, int a, int m) {
    std::vector <std::pair <int, int>> v(m);
    v[0] = { b, a };
    return v;
}

void draw_snake(std::vector<std::vector<field_element>>& v, int b, int a) {
            setfillstyle(SOLID_FILL, YELLOW);
            bar(v[b][a].left, v[b][a].top, v[b][a].right, v[b][a].bottom);
}
 
void draw_food(std::vector<std::vector<field_element>>& v, int b, int a) {
    setfillstyle(SOLID_FILL, RED);
    bar(v[b][a].left, v[b][a].top, v[b][a].right, v[b][a].bottom);
}