/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while (!st.empty()&&temperatures[i]>temperatures[st.top()]){
                result[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

