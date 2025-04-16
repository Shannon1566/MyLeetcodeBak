/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        int result=0;
        vector<int> pre(nums.size()+1,0);
        unordered_map<int,int> hashMap;

        
        for(int i=0;i<nums.size();i++){
            pre[i+1]=pre[i]+nums[i];
        }

        for(auto it:pre){
            if (hashMap.find(it - k)!=hashMap.end()) {
                result += hashMap[it - k];
            } 
            hashMap[it]++;
        }
        return result;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> nums{-1,-1,1};

    sol.subarraySum(nums,0);
    return 0;
}
