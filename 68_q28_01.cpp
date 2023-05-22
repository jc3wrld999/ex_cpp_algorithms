#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<vector<int>> club = {{11000, 40}, {8000, 30}, {400, 24}, {800, 20}, {900, 14},
                                {1800, 16}, {1000, 15}, {7000, 40}, {100, 10}, {300, 12}};
    int N = 150;
    
    int max_value = 0;
    
    // 선택하는 동아리 수를 순서대로 시험
    for (int i = 1; i <= club.size(); i++) {
        vector<int> indices(club.size());
        fill(indices.begin() + (club.size() - i), indices.end(), 1);
        
        do {
            vector<vector<int>> selected_clubs;
            
            // 선택된 동아리들을 추출
            for (int j = 0; j < club.size(); j++) {
                if (indices[j] == 1) {
                    selected_clubs.push_back(club[j]);
                }
            }
            
            // 선택한 동아리로 부원 수의 합이 조건을 만족할 때
            int sum_value_1 = accumulate(selected_clubs.begin(), selected_clubs.end(), 0,
                                         [](int sum, const vector<int>& club) {
                                             return sum + club[1];
                                         });
            
            if (sum_value_1 <= N) {
                int sum_value_2 = accumulate(selected_clubs.begin(), selected_clubs.end(), 0,
                                             [](int sum, const vector<int>& club) {
                                                 return sum + club[0];
                                             });
                max_value = max(sum_value_2, max_value);
            }
        } while (next_permutation(indices.begin(), indices.end()));
    }
    
    cout << max_value << endl;
    
    return 0;
}