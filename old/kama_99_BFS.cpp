#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dir[4][2]={0,1,1,0,-1,0,0,-1};
void bfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int x,int y){
    queue<pair<int,int>> que;
    visited[x][y]=true;
    que.push({x,y});
    while(!que.empty()){
        pair<int,int> cur=que.front();
        que.pop();
        int curx=cur.first;
        int cury=cur.second;
        
        for(int i=0;i<4;i++){
            int nxtx=curx+dir[i][0];
            int nxty=cury+dir[i][1];
            if(nxtx<0||nxtx>=grid.size()||nxty<0||nxty>=grid[0].size())
                continue;
            if(grid[nxtx][nxty]==1&&!visited[nxtx][nxty]){
                visited[nxtx][nxty]=true;
                que.push({nxtx,nxty});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int cnt=0;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(grid[i][j]==1&&visited[i][j]==false){
                cnt++;
                bfs(grid,visited,i,j);
            }
        }

    cout<<cnt<<endl;
        
    return 0;
}