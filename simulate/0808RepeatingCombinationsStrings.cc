#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    std::vector<std::string> result;
    std::string path;
    
public:

    void backtracking(const std::string& s,  std::vector<bool>& used) {
        //终止条件
        if (path.size() == s.size()) {
            result.push_back(path);
            return;
        }
        //单层遍历
        for (int i = 0; i < s.size(); i ++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && s[i] == s[i -1] && used[i -1] == false) {
                continue;
            }
            if (used[i] == true) continue;
            used[i] = true;
            path.push_back(s[i]);
            backtracking(s, used);
            path.pop_back();
            used[i] = false;
        }

    }
    std::vector<std::string> permutation(std::string S) {
        std::vector<bool> used(S.size(), false);
        backtracking(S, used);
        return result;
    }
};

int main() {
    Solution sol;
    std::string s = "qqe";
    //要去重需要先排序
    std::sort(s.begin(), s.end());
    std::vector<std::string> res = sol.permutation(s);
    for (std::string& i: res) {
        std::cout << i << " " ;
    }
    return 0;
}