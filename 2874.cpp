/*
 * @lc app=leetcode.cn id=2874 lang=cpp
 *
 * [2874] 有序三元组中的最大值 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result=0;

        vector<int> iMax(nums.size(),0);
        iMax[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            iMax[i]=max(iMax[i-1],nums[i]);
        }

        vector<int> kMax(nums.size(),0);
        kMax[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            kMax[i]=max(kMax[i+1],nums[i]);
        }


        for(int j=1;j<nums.size()-1;j++){
            if(iMax[j-1]<nums[j]) continue;
            long long cur=(long long)(iMax[j-1]-nums[j])*kMax[j+1];
            result=max(result,cur);
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums={10,13,6,2};
    sol.maximumTripletValue(nums);
    return 0;
}