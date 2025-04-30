/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        while(left<=right){
            mid=(right-left)/2+left;
            if (nums[mid]==target){
                int ll=mid,rr=mid;
                while(nums[ll]==target){
                    ll--;
                    if (ll<0) break;
                }
                ll++;
                while(nums[rr]==target){
                    rr++;
                    if (rr>nums.size()-1) break;
                }
                rr--;
                return vector<int>{ll,rr};
            }else{
                if (nums[mid]>target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
        }
        return vector<int>{-1,-1};
    }
};
// @lc code=end

