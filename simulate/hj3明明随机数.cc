#include <iostream>
#include <set>

int main() {
    int N = 0;
    std::cin >> N;
    std::set<int> numset;
    for (int i = 0; i < N; i++) {
        int num = 0;
        std::cin >> num;
        numset.insert(num);
    }
    for (int i: numset) {
        std::cout << i << std::endl;
    }
    return 0;
}