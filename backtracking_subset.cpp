#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;

        dfs(nums, 0, subset, res);

        return res;
    }

private:
    void dfs(const std::vector<int>& nums, int index, std::vector<int>& subset, std::vector<std::vector<int>>& res) {
        // 현재 부분집합 추가
        res.push_back(subset);

        // 재귀 호출을 통해 모든 경우의 수 탐색
        for (int i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);  // 현재 원소를 추가
            dfs(nums, i + 1, subset, res);  // 다음 인덱스부터 재귀 호출
            subset.pop_back();  // 추가한 원소를 제거하여 다음 경우의 수를 탐색
        }
    }
};