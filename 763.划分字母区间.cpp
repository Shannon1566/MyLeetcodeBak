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
        int hashSet[27]={0};
        for(int i=0;i<s.size();i++){
            hashSet[s[i]-'a']=i;
        }
        vector<int> result;
        int left=0;
        int right=0;
        for (int i = 0; i < s.size(); i++){
            if (hashSet[s[i]-'a']>right) right=hashSet[s[i]-'a'];
            if(i==right){
                result.emplace_back(right-left+1);
                left=right+1;
            }
        }
        return result;
    }
};
// @lc code=end

