/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include "0.cpp"
// @lc code=start
class Solution {
    vector<vector<bool>> visited;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void dfs(vector<vector<char>> &grid, int row, int col) {
        for (int i = 0; i < 4; i++) {
            int rowNxt = row + dir[i][0];
            int colNxt = col + dir[i][1];
            if (rowNxt < 0 || colNxt < 0 || rowNxt >= grid.size() || colNxt >= grid[0].size())
                continue;
            if (grid[rowNxt][colNxt] == '1'&&!visited[rowNxt][colNxt]) {
                visited[rowNxt][colNxt]=true;
                dfs(grid, rowNxt, colNxt);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int cnt = 0;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    Solution solution;
    int result = solution.numIslands(grid);

    cout << "岛屿的数量是: " << result << endl;

    return 0;
}