#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>


void findandgetword(int n , int k, std::string& x, std::vector<std::string>& wordsvec) {
    std::map<char, int> map;
    for (char i: x) {
        map[i] ++;
    }
    int nums = 0;
    std::vector<std::string> okvec;
    //遍历每个单词
    for (int i = 0; i < n; i++) {
        if (wordsvec[i] == x) continue;
        std::map<char, int> tempmap(map);
        bool flag = true;
        //遍历每个单词的字母
        for (int j = 0; j < wordsvec[i].size(); j++) {
            
            if (tempmap.find(wordsvec[i][j]) == tempmap.end()) {
                flag = false;
            }
            else {
                tempmap[wordsvec[i][j]] --;
            }
        }
        for (auto tempchar : tempmap) {
            if (tempchar.second != 0) {
                flag = false;
            }
        }
        if (flag) {
            okvec.push_back(wordsvec[i]);
            nums ++;
        }

    }
    std::cout << nums << std::endl;
    std::sort(okvec.begin(), okvec.end());
    if (k <= okvec.size()) {
        std::cout << okvec[k - 1];
    }

}

int main() {
    std::string s;
    std::getline(std::cin ,s);
    std::stringstream ss(s);
    std::string token;
    std::vector<std::string> strvec;
    while (std::getline(ss, token, ' ')) {
        strvec.push_back(token);
    }
    int n = std::stoi(strvec[0]);
    int k = std::stoi(strvec[strvec.size() - 1]);
    std::string x = strvec[strvec.size() - 2];
    std::vector<std::string> wordsvec(strvec.begin() + 1, strvec.end() - 2);
    findandgetword(n, k, x, wordsvec);
}