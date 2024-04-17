#include <vector>  // For std::vector

class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 四个方向

    void dfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // Out of bounds
            // 终止条件 就写在了 调用dfs的地方，如果遇到不合法的方向，直接不会去调用dfs。
            if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {
                dfs(grid, visited, nextx, nexty);
            }
        }
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    result++; // Increment count for each new island
                }
            }
        }
        return result;
    }
};
