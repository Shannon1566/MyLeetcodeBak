/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> c(ratings.size(),1);
        for(int i=1;i<c.size();i++){
            if(ratings[i]>ratings[i-1]){
                c[i]=c[i-1]+1;
            }
        }
        for(int i=c.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                c[i]=max(c[i],c[i+1]+1);
            }
        }
        
        int sum=0;
        for(int i=0;i<c.size();i++){
            sum+=c[i];
        }
        return sum;
    }
};
// @lc code=end

