/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

    // next[i]:不包含下标这个字符s[i]，前面的字符串中，前后缀相等长度（不包含自己！）
    void getNext(vector<int> &next,string &s){
        int i=2,j=0;

        next[0]=-1;
        if(s.length()==1) return;

        next[1]=0;
        int cn=0;
        while(i<s.length()){
            if(s[cn]==s[i-1]){
                next[i]=cn+1;
                i++;
                cn++;
            }else{
                if(cn>0){
                    cn=next[cn];
                }else{
                    next[i]=0;
                    i++;
                    if (j==-1){
                        i++;
                        j=0;
                    }
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int haystackLength=haystack.length();
        int needleLength=needle.length();
        if (haystackLength<needleLength) return -1;
        vector<int> next(needleLength);
        getNext(next,needle);
        int i=0;
        int j=0;
        
            
        while(i<haystack.length()){
            
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j=next[j];
                if (j==-1)
                {
                    j=0;
                    i++;
                }
                
            }
            if (j==needleLength) return i-j;
        }
        return -1;

    }
};
// @lc code=end

int main(){
    Solution sol;
    cout<<sol.strStr("aabaaabaaac","aabaaac")<<endl;
    return 0;
}