/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int sum=0;
    vector<int> path;
    vector<vector<int>> result;
    void backtracing(vector<int> candiates,int target,int startIndex,vector<bool>& used){
        if(sum==target){
            result.emplace_back(path);
            return;
        }else{
            for(int i=startIndex;i<candiates.size()&&sum+candiates[i]<=target;i++){
                if(i>0&&candiates[i]==candiates[i-1]&&used[i-1]==false) continue;
                used[i]=true;
                path.emplace_back(candiates[i]);
                sum+=candiates[i];
                backtracing(candiates,target,i+1,used);
                used[i]=false;
                sum-=candiates[i];
                path.pop_back();
            }
            return;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size(), false);
        backtracing(candidates,target,0,used);
        return result;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> candiates={2,5,2,1,2};
    sol.combinationSum2(candiates,5);
    return 0;
}