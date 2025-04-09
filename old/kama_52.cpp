#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,bagSize;
    cin>>n>>bagSize;
    vector<int> weigh(n);
    vector<int> value(n);
    for(int i=0;i<n;i++){
        cin>>weigh[i]>>value[i];
    }
    vector<int> dp(bagSize+1);

    for(int i=0;i<n;i++){
        for(int j=weigh[i];j<=bagSize;j++){
            dp[j]=max(dp[j],dp[j-weigh[i]]+value[i]);
        }
    }
    
    cout<<dp[bagSize]<<endl;
    return 0;
}