/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include "0.h"
// @lc code=start
class Solution {
    void myReverse(string &s,int left,int right){
        while(left<right){
            char tmp=s[left];
            s[left]=s[right];
            s[right]=tmp;
            left++;
            right--;
        }
        return;
    }
public:
    string reverseStr(string s, int k) {
        int i;
        for(int i=0;i<s.size();i+=(2*k)){
            if(i+k<s.size()){
                myReverse(s,i,i+k-1);
                continue;
            }
            myReverse(s,i,s.size()-1);
        }

        return s;
    }
};
// @lc code=end

