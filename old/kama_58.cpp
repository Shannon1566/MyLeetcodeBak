#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> preSum(n+1);
    int sum=0;
    preSum[0]=0;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        sum+=num;
        preSum[i]=sum;
    }
    int a,b;
    while(cin>>a>>b){
        cout<<preSum[b+1]-preSum[a]<<endl;
    }
    return 0;
}