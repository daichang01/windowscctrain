#include <iostream>
#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;

public:
    void backtracing(int n, int k, int startindex) {
        //终止条件
        if (path.size() == k) {
            result.push_back(path);
            return ;
        }
        //单层逻辑
        for (int i = startindex; i <= n; i++) {
            path.push_back(i);
            backtracing(n, k, i + 1);
            path.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);
        return result;
    }
};

