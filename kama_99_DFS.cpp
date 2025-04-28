#include <iostream>
#include <list>
#include <vector>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nxtX = x + dir[i][0];
        int nxtY = y + dir[i][1];
        if (nxtX < 0 || nxtX >= grid.size() || nxtY < 0 || nxtY >= grid[0].size())
            continue;
        if (grid[nxtX][nxtY] == 1 && !visited[nxtX][nxtY]) {
            visited[nxtX][nxtY] = true;
            dfs(grid, visited, nxtX, nxtY);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                cnt++;
                visited[i][j] = true;
                dfs(grid, visited, i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}