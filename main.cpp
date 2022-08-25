#include "include/graphics.h"
#include "Field.h"
#include "Snake.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<vector>

const int WIDTH = 900;
const int HEIGHT = 1000;



int main() {
    int a = 24;
    int b = 24;
    int c = 1;
    int d = 0;
    int m = 1;
    int de = 300;

    std::vector<std::vector<field_element>> vec(50, std::vector<field_element>(50));
    vec = create_field();
    std::vector <std::pair <int, int>> v_snake;
    v_snake = create_snake(b, a, m);
  
   
    initwindow(WIDTH, HEIGHT, "SnakeGame", 0, 0, true);
 
    
    //создает еду в рандомной €чейке
    srand(time(0));
    int food_y = rand() % 49;
    int food_x = rand() % 49;
   
    while (true) {
        
        setbkcolor(BLACK);
        clearviewport();

       // draw_field(vec);
          
        draw_food(vec, food_y, food_x); //рисует еду

        setcolor(WHITE);
        rectangle(50, 50, 850, 850); // рамка игрового пол€

        if (kbhit()) {

            int key = getch();
            if (key == 0) {
                key = getch();
            }
            if (key == KEY_LEFT) {
                c = -1;
                d = 0;
            }
            if (key == KEY_RIGHT) {
                c = 1;
                d = 0;
            }
            if (key == KEY_UP) {
                d = -1;
                c = 0;
            }
            if (key == KEY_DOWN) {
                d = 1;
                c = 0;
            }
        }
     
        for (int i = 0; i < m; ++i) {
            draw_snake(vec, v_snake[i].first, v_snake[i].second); // рисует змейку     
        } 
        a += c;
        b += d;
        if (a >= 51 || a < 1 || b >= 51 || b < 1) {
            c = 0;
            d = 0;
            game_over();
        }

        v_snake.push_back({ b, a });
        v_snake.erase(v_snake.begin());
    
        if (a == food_x && b == food_y) {
            ++m;
            de -= 10;
            v_snake.resize(m, { food_y, food_x });
            food_y = rand() % 50;
            food_x = rand() % 50;
        }
      
        swapbuffers();

        
                  
        delay(de);

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
