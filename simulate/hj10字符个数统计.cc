#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin , s);
    std::unordered_set<char> uset;
    for (char c: s) {
        uset.insert(c);
    }
    std::cout << uset.size() << std::endl;
    return 0;
}