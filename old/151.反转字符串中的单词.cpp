/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include "0.h"
// @lc code=start
class Solution {
    void myReverse(string &s,int left,int right){
        while(left<right){
            auto tmp=s[left];
            s[left]=s[right];
            s[right]=tmp;
            left++;
            right--;
        }
        return ;
    }
public:
    string reverseWords(string s) {
        int fast=0,slow=0;
        while(s[fast]==' '){
            fast++;
        }
        bool isSpaceTwice=false;
        while(fast<s.size()){
            if(s[fast]==' '){
                if(isSpaceTwice==false){
                    isSpaceTwice=true;
                    s[slow]=s[fast];
                    slow++;
                    fast++;
                }else{
                    fast++;
                }
            }else{
                s[slow]=s[fast];
                slow++;
                fast++;
                isSpaceTwice=false;
            }
        }
        if(s[slow-1]==' ') s.resize(slow-1);
        else s.resize(slow);
        myReverse(s,0,s.size()-1);
        int left=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                myReverse(s,left,i-1);
                left=i+1;
            }
        }
        myReverse(s,left,s.size()-1);
        return s;
    }
};
// @lc code=end

