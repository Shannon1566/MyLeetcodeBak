/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include "0.cpp"
// @lc code=start
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<vector<int>>& graph,int cur,int n){
        if(cur==n){
            result.emplace_back(path);
            return ;
        }
        for(int i=0;i<graph[cur].size();i++){
            path.emplace_back(graph[cur][i]);
            dfs(graph,graph[cur][i],n);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.emplace_back(0);
        dfs(graph,0,graph.size()-1);
        return result;
    }
};
// @lc code=end

