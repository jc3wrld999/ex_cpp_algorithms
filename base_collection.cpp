#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

int main() {

    // string find substr erase to_string stoi
    std::string str = "10.2";
    str.erase(str.find('.'), 1);  // 소수점 제거
    std::cout << str << std::endl; // 102
    str = str.substr(str.find('.') + 1, str.size());
    std::cout << str << std::endl; // 2

    // queue: push pop front back empty
    std::queue<int> myQueue;
    
    // 값을 추가하기 (push)
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    
    // 첫 번째 요소 제거하기 (pop)
    myQueue.pop();
    

    // 첫 번째 요소 접근하기 (front)
    std::cout << "Front element: " << myQueue.front() << std::endl;
    
    // 마지막 요소 접근하기 (back)
    std::cout << "Back element: " << myQueue.back() << std::endl;

    ///////////////////////////////////

    // vector: push_back pop_back erase front back empty
    std::vector<int> myVector;
    std::vector<int> myVector2(10, 0);
    
    // 값을 추가하기 (push_back)
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    
    // 첫 번째 요소 제거하기 (erase)
    myVector.erase(myVector.begin());
    
    // 마지막 요소 제거하기 (pop_back)
    myVector.pop_back();

    // 첫 번째 요소 접근하기 (front)
    std::cout << "Front element: " << myVector.front() << std::endl;
    
    // 마지막 요소 접근하기 (back)
    std::cout << "Back element: " << myVector.back() << std::endl;

    ///////////////////////////////////////////

    // std::unordered_map: insert erase begin end empty
    std::unordered_map<int, std::string> myMap;
    
    // 값을 추가하기 (insert)
    myMap.insert({1, "Apple"});
    myMap.insert({2, "Banana"});
    myMap.insert({3, "Cherry"});
    
    // 특정 키의 요소 제거하기 (erase)
    myMap.erase(myMap.end());
    
    if (myMap.count(1) > 0) {
        std::cout << "1을 포함" << std::endl;
    }

    // 첫 번째 키-값 쌍 접근하기 (begin, front)
    auto it = myMap.begin();
    std::cout << "First key: " << it->first << ", value: " << it->second << std::endl;
    
    // 마지막 키-값 쌍 접근하기 (rbegin, front)
    auto rit = myMap.end();
    std::cout << "Last key: " << rit->first << ", value: " << rit->second << std::endl;


    // std::unordered_set: insert erase begin end empty
    std::unordered_set<int> mySet;
    
    // 값을 추가하기 (insert)
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    
    // 특정 요소 제거하기 (erase)
    mySet.erase(20);
    // 값 포함 확인
    if (mySet.find(20) != mySet.end()) {
        std::cout << "Element 20 exists in the set" << std::endl;
    }

    return 0;
}