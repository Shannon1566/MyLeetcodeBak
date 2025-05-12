/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        stack<int> st;
        heights.insert(heights.begin(),0);
        heights.push_back(0);

        st.push(0);
        for(int i=1;i<heights.size();i++){
            while(heights[i]<heights[st.top()]&&!st.empty()){
                int mid=st.top();
                st.pop();
                if(!st.empty()){
                    int left=st.top();
                    int right=i;
                    int h=heights[mid];
                    int w=right-left-1;
                    res=max(res,w*h);
                }
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

