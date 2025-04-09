#include <iostream>
#include <vector>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> weight(m,0);
    vector<int> value(m,0);
    vector<vector<int>> dp(weight.size(),vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        cin>>weight[i];
    }
    for(int i=0;i<m;i++){
        cin>>value[i];
    }

    for(int i=weight[0];i<=n;i++){
        dp[0][i]=value[0];
    }
    
    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            if(weight[i]>j) 
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
        }
    }

    cout<<dp[m-1][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}