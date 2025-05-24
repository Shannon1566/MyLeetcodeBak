/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hashMap(26,0);
        for(char ch:magazine){
            hashMap[ch-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(hashMap[ransomNote[i]-'a']>0){
                hashMap[ransomNote[i]-'a']--;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

