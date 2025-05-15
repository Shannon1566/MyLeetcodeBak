#include<vector>
#include<iostream>
using namespace std;
int main(){
    int m,n;
    while(cin>>n>>m){
        vector<int> dp(n+1,0);
        dp[0]=1;
        // dp[j]:爬上第j个楼梯有dp[j]种办法
        for(int j=1;j<=n;j++){//背包
            for(int i=1;i<=m;i++){//物品
                if(j>=i) dp[j]+=dp[j-i];
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}