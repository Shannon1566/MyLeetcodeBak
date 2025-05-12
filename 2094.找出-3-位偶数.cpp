/*
 * @lc app=leetcode.cn id=2094 lang=cpp
 *
 * [2094] 找出 3 位偶数
 */
#include "0.cpp"
// @lc code=start
class Solution {
    vector<int> res;
    int path=0;
    void backtracking(vector<int>& digits,int path,int k,vector<int> &cnt){
        if(k>=3){
            res.emplace_back(path);
            return ;
        }
        for(int i=0;i<10;i++){
            if(cnt[i]>0&&(k==0&&i>0||k==1||k==2&&i%2==0)){
                cnt[i]--;
                backtracking(digits,path*10+i,k+1,cnt);
                cnt[i]++;
            }
        }
        return ;
        
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10,0);
        for(auto it:digits){
            cnt[it]++;
        }        
        backtracking(digits,0,0,cnt);
        return res;
    }
};
// @lc code=end

