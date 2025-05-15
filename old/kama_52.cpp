#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,bagSize;
    cin>>n>>bagSize;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    vector<vector<int>> dp(n,vector<int>(bagSize+1,0));

    for(int j=weight[0];j<=bagSize;j++){
        dp[0][j]=dp[0][j-weight[0]]+value[0];
    }
    // item bag
    for(int i=1;i<n;i++){
        for(int j=0;j<=bagSize;j++){
            if(j<weight[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-weight[i]]+value[i]);
        }
    }
    cout<<dp[n-1][bagSize]<<endl;
    return 0;
}