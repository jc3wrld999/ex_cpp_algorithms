#include <iostream>
#include <vector>
#include <string>

int height = 4;
int width = 7;
std::string str = "";
std::vector<std::vector<int>> tatami(height + 2, std::vector<int>(width + 2, 0));

void printTatami() {
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            if (tatami[i][j] == tatami[i][j + 1] || tatami[i][j] == tatami[i][j - 1]) {
                str += "-";
            }
            if (tatami[i][j] == tatami[i + 1][j] || tatami[i][j] == tatami[i - 1][j]) {
                str += "|";
            }
        }
        str += "\n";
    }
    str += "\n";
}

void setTatami(int h, int w, int id) {
    if (h == height + 1) {
        printTatami();
    } else if (w == width + 1) {
        setTatami(h + 1, 1, id);
    } else if (tatami[h][w] > 0) {
        setTatami(h, w + 1, id);
    } else {
        if (tatami[h - 1][w - 1] == tatami[h - 1][w] || tatami[h - 1][w - 1] == tatami[h][w - 1]) {
            if (tatami[h][w + 1] == 0) {
                tatami[h][w] = tatami[h][w + 1] = id;
                setTatami(h, w + 2, id + 1);
                tatami[h][w] = tatami[h][w + 1] = 0;
            }
            if (tatami[h + 1][w] == 0) {
                tatami[h][w] = tatami[h + 1][w] = id;
                setTatami(h, w + 1, id + 1);
                tatami[h][w] = tatami[h + 1][w] = 0;
            }
        }
    }
}

int main() {
    setTatami(1, 1, 1);
    std::cout << str << std::endl;
    return 0;
}