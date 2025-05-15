/*
 * @lc app=leetcode.cn id=3396 lang=cpp
 *
 * [3396] 使数组元素互不相同所需的最少操作次数
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> set;
        for(int i= nums.size()-1;i>=0;i--){
            if(set.find(nums[i])==set.end()){
                set.emplace(nums[i]);
            }else{
                return i/3+1;
            }
        }
        return 0;
        
    }
};
// @lc code=end

