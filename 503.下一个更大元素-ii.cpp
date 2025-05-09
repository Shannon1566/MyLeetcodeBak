/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> res(n,-1);
        for(int i=0;i<2*n;i++){
            while(!st.empty()&&nums[i%n]>nums[st.top()]){
                res[st.top()]=nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};
// @lc code=end

