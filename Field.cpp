#include "Field.h"
#include <iostream>
#include <string>
#include "include/graphics.h"
#include<vector>

std::vector<std::vector<field_element>> create_field() {
    std::vector<std::vector<field_element>> v(53, std::vector<field_element>(53));
    int y = 50;
    for (int i = 1; i < 51; ++i) {
        int x = 50;
        for (int j = 1; j < 51; ++j) {
            field_element curr;
            curr.left = x;
            curr.top = y;
            curr.right = x + 16;
            curr.bottom = y + 16;
            v[i][j] = curr;
            x += 16;
        }
        y += 16;
    }
    return v;
}

void game_over() {
    setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 7);
    outtextxy(200, 400, "GAME OVER!");
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(350, 500, "PRESS ESC");
    if (kbhit()) {
        int key = getch();
        if (key == KEY_ESC) {
            return;
        }
    }
}



