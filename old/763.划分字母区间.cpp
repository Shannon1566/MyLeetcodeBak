/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> tail(26,0);
        for(int i=0;i<n;i++){
            tail[s[i]-'a']=i;
        }
        vector<int> ans;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            end=max(end,tail[s[i]-'a']);
            if(end==i){
                ans.push_back(end-start-1);
                start=i+1;
            }
        }
        return ans;
    }
};
// @lc code=end

