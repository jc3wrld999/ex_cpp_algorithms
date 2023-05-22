#include <iostream>

int route(int width, int height, int back_y) {
    if (width == 1)
        return (back_y == height) ? back_y : back_y + 2;
    if (height == 1)
        return (back_y == 0) ? 2 : 1;
    int total = 0;
    if (back_y == 0) {
        for (int i = 0; i < height; i++) {
            total += 2 * route(width - 1, height, i + 1);
        }
    } else {
        for (int i = back_y; i <= height; i++) {
            total += route(width - 1, height, i);
        }
        total += route(width, height - 1, back_y - 1);
    }
    return total;
}

int main() {
    std::cout << route(6, 6, 0) << std::endl;
    return 0;
}



