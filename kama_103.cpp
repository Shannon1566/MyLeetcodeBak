#include <iostream>
#include <vector>
using namespace std;
const int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int curRow,int curCol){
    if(visited[curRow][curCol]==true)
        return ;
    visited[curRow][curCol]=true;
    for(int i=0;i<4;i++){
        int nxtRow=curRow+dir[i][0];
        int nxtCol=curCol+dir[i][1];
        if(nxtRow<0||nxtRow>=grid.size()||nxtCol<0||nxtCol>=grid[0].size())
            continue;
        if(grid[nxtRow][nxtCol]>=grid[curRow][curCol]){
            dfs(grid,visited,nxtRow,nxtCol);
        }
    }
    return ;
}
int main() {
    int area = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<vector<bool>> firBordar(n, vector<bool>(m, false));
    vector<vector<bool>> secBordar(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
        dfs(grid,firBordar,i,0);
        dfs(grid,secBordar,i,m-1);
    }
    for(int j=0;j<m;j++){
        dfs(grid,firBordar,0,j);
        dfs(grid,secBordar,n-1,j);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(firBordar[i][j]==true&&secBordar[i][j]==true)
                cout<<i<<' '<<j<<endl;
        }
    }
    return 0;
}