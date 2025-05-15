#include <iostream>
#include <vector>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> weight(m);
    vector<int> value(m);
    for(int i=0;i<m;i++){
        cin>>weight[i];
    }
    for(int i=0;i<m;i++){
        cin>>value[i];
    }
    //dp[i][j]:物品0..i放容量为j的背包的最大价值
    vector<vector<long long>> dp(m,vector<long long>(n+1,0));
    for(int i=0;i<=n;i++){
        if(i<weight[0]) continue;
        dp[0][i]=value[0];
    }
    for(int j=1;j<=n;j++){//bag
        for(int i=1;i<m;i++){//items
        
            if(j>=weight[i])
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
        

    cout<<dp[m-1][n];
    return 0;
}