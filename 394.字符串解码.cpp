/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include "0.cpp"
// @lc code=start
class Solution {
    int u=0;
public:
    string decodeString(string s) {
        string res;
        while(u<s.size()){
            if(isdigit(s[u])){
                int k=0;
                while(u<s.size()&&isdigit(s[u])){
                    k=k*10+s[u]-'0';
                    u++;
                }
                u++;
                string t=decodeString(s);
                while(k--){
                    res+=t;
                }
            }else if (isalpha(s[u])){
                res+=s[u];
                u++;
            }else if (s[u]==']'){
                u++;
                return res;
            }
        }
        return res;
    }
};
// @lc code=end

