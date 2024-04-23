#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool compare(std::string& a, std::string& b) {
    for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
        if (a[i] != b[i]) return a[i] < b[i];
    } 
    return a.size() < b.size(); // 如果一个字符串是另一个的前缀，则较短的字符串较小
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> strvec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strvec[i];
    }
    // std::sort(strvec.begin(), strvec.end(), [](std::string& a, std::string& b) {for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) return a[i] < b[j];});
    std::sort(strvec.begin(), strvec.end(),compare);
    // std::sort(strvec.begin(), strvec.end());这里不加比较函数也可以
    for (std::string i : strvec) {
        std::cout << i << std::endl;
    }
    return 0;
}