#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> ground(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ground[i][j];
        }
    }

    int ans=INT32_MAX;

    vector<int> preSumVertical(m);
    int preSum=0;
    for(int j=0;j<m;j++){
        int rowSum=0;
        for(int i=0;i<n;i++){
            rowSum+=ground[i][j];
        }
        preSum+=rowSum;
        preSumVertical[j]=preSum;
    }
    for(int j=0;j<m;j++){
        ans=min(ans,abs(preSum-preSumVertical[j]*2));
    }

    vector<int> preSumHorizontal(n);
    int preSum_2=0;
    for(int i=0;i<n;i++){
        int colSum=0;
        for(int j=0;j<m;j++){
            colSum+=ground[i][j];
        }
        preSum_2+=colSum;
        preSumHorizontal[i]=preSum_2;
    }
    for(int i=0;i<n;i++){
        ans=min(ans,abs(preSum_2-preSumHorizontal[i]*2));
    }

    cout<<ans;
    return 0;
}