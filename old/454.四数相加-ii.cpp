/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        unordered_map<int,int> hashMap;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                hashMap[nums1[i]+nums2[j]]++;
            }
        }

        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                auto it=hashMap.find(-(nums3[i]+nums4[j]));
                if(it!=hashMap.end()){
                    ans+=it->second;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

