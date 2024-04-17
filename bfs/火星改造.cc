#include <iostream>
#include <vector>
#include <string>
#include <queue>

int daysrequire(std::vector<std::vector<std::string>>& mars) {
    //定义四个方向
    std::vector<std::vector<int>> dir = {
        {0, 1}, {1, 0},{0, -1}, {-1, 0}
    };

    std::queue<std::pair<int, int>> que;
    for (int i = 0; i < mars.size(); i++) {
        for (int j = 0; j < mars[0].size(); j++) {
            if (mars[i][j] == "YES") {
                que.push(std::make_pair(i, j));
            }
        }
    }

    if (que.empty()) return -1;
    int days = 0;
    //开始bfs遍历
    while(!que.empty()) {
        int currentsize = que.size();
        for (int i = 0; i < currentsize; i++) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            //查看四个方向
            for (int j = 0; j < 4; j++) {
                int newX = x + dir[j][0];
                int newY = y + dir[j][1];
                if (newX >= 0 && newX < mars.size() && newY >= 0 && newY < mars[0].size() && mars[newX][newY] == "NO") {
                    mars[newX][newY] = "YES";
                    que.push(std::make_pair(newX, newY));
                }
            }
        }
        days ++;

        //结束一天后检查是否所有位置被转换为YES
        bool foundno = false;
        for (int i = 0; i < mars.size(); i++) {
            for (int j = 0; j < mars[0].size(); j++) {
                if (mars[i][j] == "NO") {
                    foundno = true;
                    break;
                }
            }
            if (foundno) break;
        }
        if (!foundno) return days;
    }

    return -1; //如果循环结束还存在NO，则返回-1表示不可能
}

int main() {
    std::vector<std::vector<std::string>> mars = {
        {"YES", "YES", "NO"},
        {"NO", "NO", "NO"},
        {"YES", "NO", "NO"}
    };

    int res = daysrequire(mars);
    if (res == -1) {
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << res << std::endl;
    }
    return 0;
}