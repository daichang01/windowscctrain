#include <iostream>
#include <string>

int main() {
    std::string numstr;
    std::getline(std::cin, numstr);
    int i = std::stoi(numstr, nullptr, 16);
    std::cout << i << std::endl;
    return 0;
}