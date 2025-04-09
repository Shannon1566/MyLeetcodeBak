/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
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

    void reverse(string &s,int reverseStart,int reverseEnd){
        int head=reverseStart;
        int tail=reverseEnd;
        char temp=0;
        while(head<tail){
            temp=s[head];
            s[head]=s[tail];
            s[tail]=temp;
            head++;
            tail--;
        }
    }
    string reverseStr(string s, int k) {
        int sLength=s.length();
        int sEnd=sLength-1;
        int cur=0;
        while (cur<sLength){
            if(sLength-cur<k){
                reverse(s,cur,sEnd);
                return s;
            }else if (sLength-cur<2*k){
                reverse(s,cur,cur+k-1);
                return s;
            }else{
                reverse(s,cur,cur+k-1);
                cur+=2*k;
            }
        }
        return s;
    }
};
// @lc code=end
int main() {
    Solution solution;
    
    solution.reverseStr("abcdefg",2);


    return 0;
}
