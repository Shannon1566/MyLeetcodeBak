/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=0,r1=nums1.size()-1,l2=0,r2=nums2.size()-1;
        // [l1,r1][l2,r2]
        while(l1<r1&&l2<r2){
            if(nums1[l1]<nums2[l2]){
                l1++;
            }else{
                l2++;
            }

            if(nums1[r1]>nums2[r2]){
                r1--;
            }else{
                r2--;
            }
        }
    }
};
// @lc code=end

