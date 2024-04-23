#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    int k;
    std::cin >> k;
    if (k == 0) {
        std::sort(nums.begin(), nums.end());
        for (int i : nums) {
            std::cout << i << " ";
        }
    }
    if (k == 1) {
        std::sort(nums.begin(), nums.end(), [](int& a, int& b) {return a > b;});
        for (int i : nums) {
            std::cout << i << " ";
        }
    }
}