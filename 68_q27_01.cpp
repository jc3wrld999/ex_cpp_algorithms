#include <iostream>
#include <vector>
using namespace std;

const int W = 6;
const int H = 4;
const vector<vector<int>> DIR = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int search(int x, int y, int dir, vector<int>& left, vector<int>& bottom) {
    vector<int> left_l = left;
    vector<int> bottom_l = bottom;

    // Check if out of bounds or already used
    if (dir == 0 || dir == 2) { // Up or down
        int pos = min(y, y + DIR[dir][1]);
        if (pos < 0 || y + DIR[dir][1] > H)
            return 0;
        if (left_l[pos] & (1 << x) > 0)
            return 0;
        left_l[pos] |= (1 << x); // Mark vertical line as used
    } else { // Left or right
        int pos = min(x, x + DIR[dir][0]);
        if (pos < 0 || x + DIR[dir][0] > W)
            return 0;
        if (bottom_l[pos] & (1 << y) > 0)
            return 0;
        bottom_l[pos] |= (1 << y); // Mark horizontal line as used
    }

    int next_x = x + DIR[dir][0];
    int next_y = y + DIR[dir][1];

    if (next_x == W && next_y == H)
        return 1; // Reached the goal

    int cnt = 0;
    // Move straight
    cnt += search(next_x, next_y, dir, left_l, bottom_l);
    // Turn left
    dir = (dir + 1) % DIR.size();
    cnt += search(next_x, next_y, dir, left_l, bottom_l);
    return cnt;
}

int main() {
    vector<int> left(H, 0);   // Vertical lines used
    vector<int> bottom(W, 0); // Horizontal lines used

    cout << search(0, 0, 3, left, bottom) << endl;

    return 0;
}