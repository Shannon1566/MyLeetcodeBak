#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    vector<int> dp(m+1,0);
    for(int i=0;i<n;i++){
        for(int j=weight[i];j<=m;j++){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[m]<<endl;

    return 0;
}