#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> gettwosum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }
            else {
                umap[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};

int main() {
    std::vector<int> nums = {20, 70, 110, 150};
    int target = 260;
    Solution sol;
    std::vector<int> res =  sol.gettwosum(nums, target);
    for (int i: res) {
        std::cout << i+1 << " ";
    }
    return 0;
}