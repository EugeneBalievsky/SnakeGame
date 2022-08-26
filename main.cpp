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
    int second_bound = 51;
    int first_bound = 1;
    int x = 24;
    int y = 24;
    int dx = 1;
    int dy = 0;
    int s_size = 1;
    int de = 300;

    std::vector<std::vector<field_element>> vec(50, std::vector<field_element>(50));
    vec = create_field();
    std::vector <std::pair <int, int>> v_snake;
    v_snake = create_snake(y, x, s_size);
  
   
    initwindow(WIDTH, HEIGHT, "SnakeGame", 0, 0, true);
 
    
    //создает еду в рандомной €чейке
    srand(time(0));
    int food_y = rand() % 49+1;
    int food_x = rand() % 49+1;
   
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
                dx = -1;
                dy = 0;
            }
            if (key == KEY_RIGHT) {
                dx = 1;
                dy = 0;
            }
            if (key == KEY_UP) {
                dy = -1;
                dx = 0;
            }
            if (key == KEY_DOWN) {
                dy = 1;
                dx = 0;
            }
        }
     
        for (int i = 0; i < s_size; ++i) {
            draw_snake(vec, v_snake[i].first, v_snake[i].second); // рисует змейку     
        } 
        x += dx;
        y += dy;
        if (x >= second_bound || x < first_bound || y >= second_bound || y < first_bound) {
            dx = 0;
            dy = 0;
            game_over();
        }

        v_snake.push_back({ y, x });
        v_snake.erase(v_snake.begin());
    
        if (x == food_x && y == food_y) {
            ++s_size;
            de -= 10;
            v_snake.resize(s_size, { food_y, food_x });
            food_y = rand() % 49+1;
            food_x = rand() % 49+1;
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
