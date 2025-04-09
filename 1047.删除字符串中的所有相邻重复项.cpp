/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <iostream>
#include <stack>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]==st.top()){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            result.insert(0,1,st.top());
            st.pop();
        }

        return result;
    }
};
// @lc code=end

