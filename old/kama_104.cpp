#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int n, m;
int maxArea;
int curArea;
int bfs(vector<vector<int>> &grid, int curRow, int curCol) {
    int res = 0;
    vector<vector<int>> visited(n, vector<int>(m, false));
    queue<pair<int, int>> que;
    que.push({curRow, curCol});
    visited[curRow][curCol] = true;
    res++;
    while (!que.empty()) {
        curRow=que.front().first;
        curCol=que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nxtRow = curRow + dir[i][0];
            int nxtCol = curCol + dir[i][1];
            if (nxtCol < 0 || nxtCol >= m || nxtRow < 0 || nxtRow >= n)
                continue;
            if (visited[nxtRow][nxtCol] == true)
                continue;
            if (grid[nxtRow][nxtCol] == 1) {
                res++;
                que.push({nxtRow,nxtCol});
                visited[nxtRow][nxtCol]=true;
            }
        }
    }
    return res;
}
int main() {
    cin >> n >> m;
    bool isAllLand=true;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j]==0) isAllLand=false;
        }
            
    if(isAllLand){
        cout<<m*n<<endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                curArea = bfs(grid, i, j);
                maxArea=curArea>maxArea?curArea:maxArea;
            }
        }
    cout<<maxArea<<endl;
    return 0;
}