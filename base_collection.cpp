#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
using namespace std;

template<typename Key, typename Value>

int main() {

    
    // string 
    // find substr erase to_string stoi
    string str = "10.2";
    str.erase(str.find('.'), 1);  // 소수점 제거 102
    str = str.substr(str.find('.') + 1, str.size()); // 2


    // queue
    // push pop front back empty
    queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.pop();
    int first_queue = myQueue.front();
    int last_queue = myQueue.back();
    bool is_empty_queue = myQueue.empty();
    int size_queue = myQueue.size();

    // pq
    // push pop top empty size
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(20);
    pq.pop(); // 우선순위 큐에서 가장 우선순위가 높은 요소를 제거
    int topElement = pq.top();
    bool is_empty_pq = pq.empty();
    int size_pq = pq.size();


    // pair
    // first, second
    pair<int, string> p1(42, "Hello");
    pair<int, string> p2(42, "World");
    int first_pair = p1.first;
    string first_pair = p1.second;
    bool is_equal = p1 == p2;
    bool is_not_equal = p1 != p2;


    // vector
    // push_back pop_back erase front back empty
    vector<int> myVector;
    vector<int> myVector2(10, 0);
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    vector<pair<int, int>> myVector;

    // emplace_back을 사용하여 pair 요소 추가
    myVector.emplace_back(1, 2);
    myVector.emplace_back(3, 4);
    
    myVector.erase(myVector.begin()); // 첫 번째 요소 제거하기
    myVector.pop_back(); // 마지막 요소 제거하기
    int first_v = myVector.front();
    int last_v = myVector.back();

    // 중복 제거1
    vector<vector<int>> answer;
    vector<vector<int>> uniqueAnswer;
    for (const auto& item : answer) {
        if (find(uniqueAnswer.begin(), uniqueAnswer.end(), item) == uniqueAnswer.end()) { // 중복 확인
        uniqueAnswer.push_back(item);
        }
    }

    // 중복 제거2
    unordered_set<vector<int>> uniqueAnswer(answer.begin(), answer.end());


    // unordered_map
    // insert erase begin end empty size
    unordered_map<int, string> myMap;
    
    // 값을 추가하기 (insert)
    myMap.insert({1, "Apple"});
    myMap.insert({2, "Banana"});
    myMap.insert({3, "Cherry"});
    myMap.erase(myMap.end());     // 특정 키의 요소 제거하기
    
    if (myMap.count(1) > 0) {
        cout << "1을 포함" << endl;
    }

    // 첫 번째 키-값 쌍 접근하기 (begin, front)
    auto it = myMap.begin();
    auto key_map = it->first;
    auto value_map = it->second;

    // 마지막 키-값 쌍 접근하기 (rbegin, front)
    auto rit = myMap.end();
    auto key_map = rit->first;
    auto value_map = rit->second;

    int size_map = myMap.size();

    // key별로 value를 그룹화
    unordered_map<Key, std::vector<Value>> groupedMap;
    
    // map의 각 요소를 순회하면서 key별로 value를 그룹화
    for (const auto& pair : myMap) {
        groupedMap[pair.first].push_back(pair.second);
    }

    // key별로 그룹화된 value 출력
    for (const auto& pair : groupedMap) {
        auto key = pair.first;
        for (const auto& value : pair.second) {
            cout << value << " ";
        }
        cout << endl;
    }

    // unordered_set
    // insert erase begin end empty
    unordered_set<int> mySet;
    
    // 값을 추가하기 (insert)
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.erase(20);
    // 값 포함 확인
    if (mySet.find(20) != mySet.end()) {
        cout << "Element 20 exists in the set" << endl;
    }

    return 0;
}