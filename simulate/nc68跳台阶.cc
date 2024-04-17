#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number int整型 
     * @return int整型
     */
    int jumpFloor(int number) {
        std::vector<int> dp(number+1, 0);
        if (number == 1) return 1;
        if (number == 2) return 2; 
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        // for (int i : dp) {
        //     std::cout << i << " ";
        // }
        return dp[number];

    }
};
 
int main() {
    int n;
    std::cin >> n;
    Solution sol;
    int res = sol.jumpFloor(n);
    std::cout << res << std::endl;
    return 0;
}