#include <iostream>
#include <string>
#include <sstream>

unsigned long iptonum(std::string& s) {
    std::string token;
    std::stringstream ss(s);
    //从字符串解析数据
    unsigned long  result = 0;
    while (std::getline(ss, token, '.')) {
        result = (result << 8) + std::stoi(token);
    }
    return result;
}

std::string numtoip(std::string& l) {
    unsigned long num = std::stoul(l);
    std::stringstream ss;
    //字符串拼接和转换
    ss << ((num >> 24) & 0xFF) << '.' << ((num >> 16) & 0xFF) << '.'
    << ((num >> 8) & 0xFF) << '.' << (num & 0xFF);
    std::string res = ss.str();
    return res;
}


int main() {
    std::string s;
    std::string l;

    std::getline(std::cin, s);
    // std::cin.ignore();
    std::getline(std::cin, l);
    unsigned long  ipnum = iptonum(s);
    std::string ip = numtoip(l);
    std::cout << ipnum << std::endl;
    std::cout << ip << std::endl;
    return 0;
}