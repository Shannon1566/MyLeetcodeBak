/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> hashSet;
        for(auto it:nums1){
            hashSet.emplace(it);
        }
        for(auto num:nums2){
            auto it=hashSet.find(num);
            if(it!=hashSet.end()){
                ans.emplace_back(num);
                hashSet.erase(num);
            }
        }
        return ans;
    }
};
// @lc code=end

