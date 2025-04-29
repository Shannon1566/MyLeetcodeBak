#include <iostream>
#include <vector>
using namespace std;
const int dir[4][2]={0,1,1,0,-1,0,0,-1};
int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int curRow,int curCol){
    int nxtArea=0;
    if(grid[curRow][curCol]==0)
        return 0;
    visited[curRow][curCol]=true;
    for(int i=0;i<4;i++){
        int nxtRow=curRow+dir[i][0];
        int nxtCol=curCol+dir[i][1];
        if(nxtCol<0||nxtCol>=grid[0].size()||nxtRow<0||nxtRow>=grid.size()||visited[nxtRow][nxtCol]==true)
            continue;
        nxtArea+=dfs(grid,visited,nxtRow,nxtCol);
    }
    return nxtArea+1;
    
}
int main(){
    int curArea,maxArea=0;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(grid[i][j]==1&&visited[i][j]==false){
                visited[i][j]=true;
                curArea=dfs(grid,visited,i,j);
                maxArea=curArea>maxArea?curArea:maxArea;
            }
            
        }
    cout<<maxArea<<endl;
    return 0;
}