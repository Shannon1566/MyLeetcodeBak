/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> res(n,-1);
        stack<int> st;
        unordered_map<int,int> hashSet;
        for(int i=0;i<m;i++){
            while(!st.empty()&&nums2[i]>nums2[st.top()]){
                hashSet.emplace(nums2[st.top()],nums2[i]);
                st.pop();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            auto it =hashSet.find(nums1[i]);
            if(it!=hashSet.end()){
                res[i]=it->second;
            }
        }

        return res;
    }
};
// @lc code=end

