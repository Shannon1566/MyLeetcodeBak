/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int midIndex = st.top();
                st.pop();
                if (!st.empty()) {
                    int leftIndex = st.top();
                    int h = min(height[leftIndex], height[i])-height[midIndex];
                    int w = i - leftIndex - 1;
                    res += h * w;
                }
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
