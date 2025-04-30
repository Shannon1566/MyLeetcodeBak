/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int tryTarget=(right-left)/2+left;
            if (nums[tryTarget]==target){
                return tryTarget;
            }else{
                if (nums[tryTarget]>target){
                    right=tryTarget-1;
                }else{
                    left=tryTarget+1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

