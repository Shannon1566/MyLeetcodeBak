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
        vector<int> ans(nums1.size(),-1);
        // for(int i=0;i<nums1.size();i++){
        //     int j;
        //     for(j=0;j<nums2.size();j++){
        //         if(nums1[i]==nums2[j])
        //             break;
        //     }
        //     if(j==nums2.size()) continue;
        //     int cur=nums2[j];
        //     for(;j<nums2.size();j++){
        //         if(cur<nums2[j]){
        //             ans[i]=nums2[j];
        //             break;
        //         } 
        //     }
        // }
        stack<int> st;
        if(nums1.size()==0) return ans;
        unordered_map<int,int> umap;
        for(int i=0;i<nums1.size();i++){
            umap[nums1[i]]=i;
        }
        st.push(0);
        for(int i=1;i<nums2.size();i++){
            if(nums2[i]<=nums2[st.top()])
                st.push(i);
            else{
                while(!st.empty()&&nums2[i]>nums2[st.top()]){
                    if(umap.count(nums2[st.top()])>0){
                        int index =umap[nums2[st.top()]];
                        ans[index]=nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end

