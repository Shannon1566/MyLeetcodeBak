#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    int min=INT32_MAX;
    vector<vector<int>> tudi_origin(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tudi_origin[i][j];
        }
    }
    
    // vertical
    vector<int> vartical(m);
    int sum=0;
    for (int i=0;i<m;i++){
        
        for (int j=0;j<n;j++){
            vartical[i]+=tudi_origin[j][i];
        }
        sum+=vartical[i];
        vartical[i]=sum;   
    }

    // horizontal
    sum=0;
    vector<int> horizontal(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            horizontal[i]+=tudi_origin[i][j];
        }
        sum+=horizontal[i];
        horizontal[i]=sum;   
    }

    int result=0;
    for (int i=0;i<m;i++){
        result=vartical[m-1]-vartical[i]-vartical[i];
        result=abs(result);
        min=result<min?result:min;
    }

    for (int i=0;i<n;i++){
        result=horizontal[n-1]-horizontal[i]-horizontal[i];
        result=abs(result);
        min=result<min?result:min;
    }

    cout<<min;
    return 0;
}
