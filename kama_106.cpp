#include <iostream>
#include <vector>
using namespace std;
int main() {
    const int dir[4][2]={0,1,1,0,0,-1,-1,0};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int ans=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if(grid[i][j]==0)
                continue;
            for(int k=0;k<4;k++){
                int nxtRow=i+dir[k][0];
                int nxtCol=j+dir[k][1];
                if(nxtCol<0||nxtCol>=m||nxtRow<0||nxtRow>=n)
                    ans++;
                else if(grid[nxtRow][nxtCol]==0)
                    ans++;
            }
        }
    cout<<ans<<endl;
}