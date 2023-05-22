#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// 스레드로 실행될 함수
void threadFunction(int threadID) {
    cout << "Thread " << threadID << " started" << endl;
    // 스레드가 수행할 작업을 여기에 추가
    cout << "Thread " << threadID << " finished" << endl;
}

int main() {
    // 스레드 컨테이너
    vector<thread> threads;
    int numThreads = 4; // 생성할 스레드 개수

    // 스레드 생성
    for (int i = 0; i < numThreads; i++) {
        threads.push_back(thread(threadFunction, i));
    }

    // 생성된 스레드 조인
    for (auto& thread : threads) {
        // 현재 스레드가 호출된 스레드가 종료될 때까지 대기하며, 호출한 스레드가 종료되면 다음 코드로 넘어감
        // 각 스레드의 종료를 동기화하여 프로그램이 정상적으로 종료되도록 보장하는 역할
        thread.join(); 

    }

    return 0;
}