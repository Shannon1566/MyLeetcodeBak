#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,bagSize;
    cin>>n>>bagSize;
    vector<int> v(n);
    vector<int> w(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<int> dp(bagSize+1,0);
    for(int i=0;i<n;i++){
        for(int j=w[i];j<=bagSize;j++){
            dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
        }
    }
    cout<<dp[bagSize]<<endl;
    return 0;
}