#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    std::map<char, int> charsmap;
    for (int i = 0; i < s.size(); i++) {
        charsmap[s[i]] ++;
    }
    std::vector<std::pair<char, int>> charsvec(charsmap.begin(), charsmap.end());
    std::sort(charsvec.begin(), charsvec.end(), [](std::pair<char, int>&a, std::pair<char, int>& b){return a.second <= b.second;});
    int mintime = charsvec[0].second;
    for (auto i : charsvec) {
        if (i.second == mintime) {
            while (s.find(i.first) != std::string::npos) {
                s.erase(s.find(i.first), 1);
            }
        }
    }
    std::cout << s << std::endl;
    return 0;
   
}