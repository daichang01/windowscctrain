#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

bool compare0(const std::pair<int, int>& a,const std::pair<int, int>& b) {
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

bool compare1(const std::pair<int, int>& a,const std::pair<int, int>& b) {
    if (a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

void scoresSequence(int way, std::vector<std::string>& names, std::unordered_map<int, int>& scoresmap) {
    std::vector<std::pair<int,int>> scoresvec(scoresmap.begin(), scoresmap.end());
    if (way == 0) {
        std::sort(scoresvec.begin(), scoresvec.end(), compare0);
    }
    else{
        std::sort(scoresvec.begin(), scoresvec.end(), compare1);
    }
    for (std::pair<int,int>& i: scoresvec) {
        std::cout << names[i.first] << " " << i.second << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    int way;
    std::cin >> way;
    std::vector<std::string> names(n,"");
    std::unordered_map<int, int> scoresmap;
    for (int i = 0; i < n; i++) {
        std::cin >> names[i];
        std::cin >> scoresmap[i];
    }
    scoresSequence(way, names, scoresmap);
}