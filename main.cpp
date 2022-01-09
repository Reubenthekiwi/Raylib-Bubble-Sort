#include "raylib.h"
#include <iostream>
#include <ctime>

constexpr int WINDOW_WIDTH{800}, WINDOW_HEIGHT{600}, FPS{320}, BAR_WIDTH{10};

struct BAR {
    unsigned int y;
    unsigned int height;
    Color color;
};

void generateBars(BAR *array, size_t arr_size);
void bubbleSort(BAR *array, size_t arr_size, int i);

int main() {

    bool sorting = false, sorted = false;
    int step, index;

    BAR bars[WINDOW_WIDTH / BAR_WIDTH];
    int barsCount = sizeof(bars)/sizeof(bars[0]);

    generateBars(bars, barsCount);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bubble Sort");

    SetTargetFPS(FPS);

    std::cout << "8th element's height (AT INIT): " << bars[7].height << std::endl;
    
    while(!WindowShouldClose()) {

        // input
        if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
            if (!sorting & !sorted) {
                sorting = true;
                sorted = false;
                step = 0, index = 0;
            }
        } else if(IsKeyPressed(KEY_BACKSPACE)) {
            generateBars(bars, barsCount);
            sorted = false;
        }

        // updating
        if(sorting) {
            if(step < barsCount) {
                if(index < barsCount - step) {
                    bubbleSort(bars, barsCount, index);
                    index++;
                } else {
                    index = 0;
                    step++;
                }
            } else {
                std::cout << "ALL SORTED SUCCESSFULLY!" << std::endl;
                sorting = false;
                sorted = true;
            }
        }

        // rendering

        BeginDrawing();
        
        ClearBackground(BLACK);
        
        if(!sorted)
            for(int i = 0; i < barsCount; i++) {DrawRectangle(i * BAR_WIDTH + BAR_WIDTH / 10, bars[i].y, BAR_WIDTH - BAR_WIDTH / 10, bars[i].height, bars[i].color);}
        else
            for(int i = 0; i < barsCount; i++) {DrawRectangle(i * BAR_WIDTH + BAR_WIDTH / 10, bars[i].y, BAR_WIDTH - BAR_WIDTH / 10, bars[i].height, GREEN);}

        EndDrawing();

    }
    
    CloseWindow();

    return 0;
}

void generateBars(BAR *array, size_t arr_size) {
    SetRandomSeed(time(0));
    for (unsigned int i = 0; i < arr_size; i++) {
        array[i].height = GetRandomValue(10, WINDOW_HEIGHT);
        array[i].y = WINDOW_HEIGHT - array[i].height;
        array[i].color = WHITE;
    }
}

void bubbleSort(BAR *array, size_t arr_size, int i) {
    std::cout << "COMPARISON " << i + 1 << std::endl;
    if (array[i].height > array[i + 1].height) {
        array[i].color = RED;
        std::cout << "Element " << i << "'s height BEFORE = " << array[i].height << std::endl;
        std::cout << "Element " << i+1 << "'s height BEFORE = " << array[i+1].height << std::endl;
        // swapping elements if elements
        BAR temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        std::cout << "Element " << i << "'s height AFTER = " << array[i].height << std::endl;
        std::cout << "Element " << i+1 << "'s height AFTER = " << array[i+1].height << std::endl;
    }
    array[i].color = WHITE;
}