#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> value(m);
    vector<int> weight(m);
    for(int i=0;i<m;i++){
        cin>>weight[i];
    }
    for(int i=0;i<m;i++){
        cin>>value[i];
    }

    // vector<vector<int>> dp(m,vector<int>(n+1,0));
    vector<int> dp(n+1,0);

    for(int i=0;i<m;i++){
        for(int j=n;j>=weight[i];j--){
                dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }

    cout<<dp[n]<<endl;

    // for(int i=1;i<m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    return 0;
}