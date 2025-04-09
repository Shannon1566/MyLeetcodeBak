/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty()) return false;
                switch (st.top())
                {
                case '(':
                    if (c == ')')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '[':
                    if (c == ']')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                default:
                    if (c == '}')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end
