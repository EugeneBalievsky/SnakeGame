#include "include/graphics.h"
#include "Field.h"
#include <iostream>
#include <string>
#include <algorithm>
const int WIDTH = 900;
const int HEIGHT = 1000;


int main() {
    srand(time(0));

    initwindow(WIDTH, HEIGHT, "SnakeGame", 0, 0, true);
    int y = 50;
    for (int i = 0; i < MAX_Y; ++i) {
        int x = 50;
        for (int j = 0; j < MAX_X; ++j) {
            create_field(x, y, x + 16, y + 16, i, j);
            x += 16;
        }
        y += 16;
    }
    
    while (true) {

        setbkcolor(BLACK);
        clearviewport();

        draw_field();

        swapbuffers();
        delay(30);



        if (kbhit()) {
            int key = getch();
            if (key == KEY_ESC) {
                break;
            }
        }
    }


    closegraph();


    return 0;
}
