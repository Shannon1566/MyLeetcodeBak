/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        unordered_set<int> set;
        vector<int> result;
        for (int i=0;i<n1;i++){
            set.insert(nums1[i]);
        }

        for (int i=0;i<n2;i++){
            auto it=set.find(nums2[i]);
            if (it!=set.end()){
                result.emplace_back(nums2[i]);
                set.erase(nums2[i]);
            }
        }
        return result;

    }
};
// @lc code=end

