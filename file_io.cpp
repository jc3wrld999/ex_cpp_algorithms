#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read_file() {
    ifstream inputFile("input.txt"); // 입력 파일 열기

    if (inputFile.is_open()) { // 파일이 성공적으로 열렸는지 확인
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl; // 파일 내용 출력
        }

        inputFile.close(); // 파일 닫기
    } else {
        cout << "파일을 열 수 없습니다." << endl;
    }
}

void write_file() {

    ofstream outputFile("output.txt"); // 출력 파일 열기

    if (outputFile.is_open()) { // 파일이 성공적으로 열렸는지 확인
        string message = "Hello, world!";
        outputFile << message << endl; // 파일에 내용 쓰기

        outputFile.close(); // 파일 닫기
    } else {
        cout << "파일을 열 수 없습니다." << endl;
    }
}

int main() {

    return 0;
}