/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include "0.h"
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashMap(26,0);
        for(auto ch:s){
            hashMap[ch-'a']++;
        }

        for(auto ch:t){
            if(hashMap[ch-'a']>0){
                hashMap[ch-'a']--;
            }else{
                return false;
            }
        }
        for(auto it:hashMap){
            if(it!=0) 
                return false;
        }
        return true;
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.isAnagram("anagram","nagaram");
    return 0;
}
