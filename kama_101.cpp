#include <iostream>
#include <vector>
using namespace std;
const int dir[4][2]={0,1,1,0,-1,0,0,-1};
void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int curRow,int curCol){
    if(grid[curRow][curCol]==0)
        return;
    visited[curRow][curCol]=true;
    grid[curRow][curCol]=0;
    for(int i=0;i<4;i++){
        int nxtRow=curRow+dir[i][0];
        int nxtCol=curCol+dir[i][1];
        if(nxtCol<0||nxtCol>=grid[0].size()||nxtRow<0||nxtRow>=grid.size()||visited[nxtRow][nxtCol]==true)
            continue;
        dfs(grid,visited,nxtRow,nxtCol);
    }
    return ;
}
int main(){
    int area=0;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<m;i++){
        if(grid[0][i]==1) dfs(grid,visited,0,i);
        if(grid[n-1][i]==1) dfs(grid,visited,n-1,i);
    }
    for(int i=0;i<n;i++){
        if(grid[i][0]==1) dfs(grid,visited,i,0);
        if(grid[i][m-1]==1) dfs(grid,visited,i,m-1);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==1) area++;

    cout<<area<<endl;
    return 0;
}