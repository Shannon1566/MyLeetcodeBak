/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hashMap;
        int magazineLength=magazine.length();
        for (int i=0;i<magazineLength;i++){
            hashMap[magazine[i]]++;
        }

        int ransomNoteLength=ransomNote.length();
        for (int i=0;i<ransomNoteLength;i++){
            auto it = hashMap.find(ransomNote[i]);
            if (it!=hashMap.end()){
                hashMap[ransomNote[i]]--;
                if (hashMap[ransomNote[i]]==0) hashMap.erase(ransomNote[i]);
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

