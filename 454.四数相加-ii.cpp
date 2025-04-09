/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int,int> map;
        int cnt=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                map[nums1[i]+nums2[j]]++;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                int num34=nums3[i]+nums4[j];
                auto it=map.find(-num34);
                if (it!=map.end()){
                    cnt+=it->second;
                }
            }
        }

        return cnt;
        

    }
};
// @lc code=end

