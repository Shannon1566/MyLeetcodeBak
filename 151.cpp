/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:

    void reverse(string &s,int head,int tail){
        int temp=0;
        while(head<tail){
            temp=s[head];
            s[head]=s[tail];
            s[tail]=temp;
            head++;
            tail--;
        }
    }

    

    string reverseWords(string s) {
        int noSpaceHead=0;
        int sLength=s.length();
        while (s[noSpaceHead]==' ') noSpaceHead++;
        int fast=noSpaceHead,slow=noSpaceHead;
        for(;fast<sLength;fast++){
            if((s[fast]!=' ')||(fast>0&&s[fast]==' '&&s[fast-1]!=' '))
            {
                s[slow]=s[fast];
                slow++;
            }
        }
        int noSpaceTail=0;
        if (s[slow-1]==' ') noSpaceTail=slow-2;
        else noSpaceTail=slow-1;
        
        reverse(s,noSpaceHead,noSpaceTail);
        
        int reverseBegin=noSpaceHead;
        for (int i=noSpaceHead;i<=noSpaceTail;i++){
            if(s[i]==' '){
                reverse(s,reverseBegin,i-1);
                reverseBegin=i+1;
            }

            if(i==noSpaceTail) reverse(s,reverseBegin,i);
        }
        return s.substr(noSpaceHead,noSpaceTail-noSpaceHead+1);
        
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.reverseWords("  hello world  ");
    return 0;
}
