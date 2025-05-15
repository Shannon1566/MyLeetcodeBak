#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,a,b,sum=0,inputNum;
    cin>>n;
    vector<int> vec(n);
    for (int i=0;i<n;i++){
        cin>>inputNum;
        sum+=inputNum;
        vec[i]=sum;
    }
    while(cin>>a>>b){
        if (a==0){
            cout<<vec[b]<<endl;
        }else{
            cout<<vec[b]-vec[a-1]<<endl;
        }
        
    }
    return 0;
}