#include <iostream>
#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> dir = {
        {0, 1}, {1, 0},{0, -1}, {-1, 0}
    };

     void dfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& visited, int x, int y) {
        //终止条件
        if (grid[x][y] == '0' || visited[x][y] == 1) {
            return;
        }
        visited[x][y] = 1;
        //遍历四个方向
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
                continue;
            }
            dfs(grid, visited, nextx, nexty);
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
                    dfs(grid, visited, i, j);
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
    int res = sol.numIslands(grid);
    std::cout << res << std::endl;
}