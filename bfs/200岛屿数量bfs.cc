#include <iostream>
#include <vector>
#include <queue>

class Solution {
private:
    std::vector<std::vector<int>> dir = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    void bfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& visited, int x, int y  ) {
        std::queue<std::pair<int, int>> que;
        que.push(std::pair<int,int>(x, y));
        visited[x][y] = 1; //只要加入队列，立刻标记
        //开始遍历
        while (!que.empty()) {
            std::pair<int, int> cur = que.front();
            que.pop();
            int curx = cur.first;
            int cury = cur.second;
            //遍历四个方向
            for(int i= 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
                if (visited[nextx][nexty] == 0 && grid[nextx][nexty] == '1') {
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = 1;
                }
            }
        }
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int count = 0;
        std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    bfs(grid, visited, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Solution sol;
    int result = sol.numIslands(grid);
    std::cout << result << std::endl;
    return 0;
}