/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1) return;
        int fast=0,slow=0;
        while(fast<nums.size()){
            if(nums[fast]==0){
                fast++;
            }else{
                nums[slow]=nums[fast];
                slow++;
                fast++;
            }
            
        }
        for(slow;slow<nums.size();slow++){
            nums[slow]=0;
        }
    }
};

int main(){
    vector<int> nums{1,0};
    Solution sol;
    sol.moveZeroes(nums);
    return 0;
}
// @lc code=end

