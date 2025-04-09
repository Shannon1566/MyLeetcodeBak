/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        vector<int> result;
        for (int i=0;i<n;i++){
            auto it=map.find(nums[i]);
            if(it!=map.end()){
                result.emplace_back(it->second);
                result.emplace_back(i);
            }else{
                map.insert({target-nums[i],i});
            }
        }
        return result;
    }
};
// @lc code=end

