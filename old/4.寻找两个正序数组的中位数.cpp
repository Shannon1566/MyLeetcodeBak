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
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        int m=nums1.size(),n=nums2.size();
        nums1.insert(nums1.begin(),INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.insert(nums2.begin(),INT_MIN);
        nums2.push_back(INT_MAX);

        int i=0,j=(m+n+1)/2;
        while(true){
            if(nums1[i]<=nums2[j+1]&&nums1[i+1]>nums2[j]){
                int max1=max(nums1[i],nums2[j]);
                int min2=min(nums1[i+1],nums2[j+1]);
                return (m+n)%2?max1:(max1+min2)/2.0;
            }
            i++;
            j--;
        }

    }
};
// @lc code=end

