/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hashMap;
        int sLength=s.length();
        int tLength=t.length();
        for (int i=0;i<sLength;i++){
            hashMap[s[i]]++;
        }
        for (int i=0;i<tLength;i++){
            auto it = hashMap.find(t[i]);
            if (it!=hashMap.end()){
                hashMap[t[i]]--;
                if(hashMap[t[i]]==0) 
                    hashMap.erase(t[i]);
            }else{
                return false;
            }
        }
        if(hashMap.empty()){
            return true;
        }else{
            return false;
        }
    }
};
int main(){
    Solution solution;
    solution.isAnagram("anagram","nagaram");
    return 0;
}
// @lc code=end

