#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(const vector<vector<int>>& graph,int cur,int n){
    if(cur==n){
        result.emplace_back(path);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(graph[cur][i]==1){
            path.emplace_back(i);
            dfs(graph,i,n);
            path.pop_back();
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int s,t;
    vector<vector<int>> graph(n+1,vector<int>(n+1,0));
    while(m--){
        cin>>s>>t;
        graph[s][t]=1;
    }
    
    path.push_back(1);
    dfs(graph,1,n);

    if(result.empty()) cout<<-1<<endl;
    for(const vector<int>& pa:result){
        for(int i=0;i<pa.size()-1;i++){
            cout<<pa[i]<<' ';
        }
        cout<<pa[pa.size()-1]<<endl;
    }
    
    return 0;
}