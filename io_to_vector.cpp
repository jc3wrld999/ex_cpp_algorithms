#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, columns;
    cout << "행 수를 입력하세요: ";
    cin >> rows;
    cout << "열 수를 입력하세요: ";
    cin >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));

    cout << "행렬 요소를 입력하세요:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "입력한 2차원 배열:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}