/*
 * @lc app=leetcode.cn id=3305 lang=cpp
 *
 * [3305] 元音辅音字符串计数 I
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool isValid(unordered_map<char, int> &hashMap, int fuyin, int k) {
        for (auto it : hashMap) {
            if (it.second == 0) return false;
        }
        if (fuyin != k) return false;
        return true;
    }
    void addChar(unordered_map<char, int> &hashMap,int& fuyin,char c){
        auto it=hashMap.find(c);
        if(it!=hashMap.end()){
            hashMap[c]++;
        }else{
            fuyin++;
        }
    }
    void delChar(unordered_map<char, int> &hashMap,int& fuyin,char c){
        auto it=hashMap.find(c);
        if(it!=hashMap.end()){
            hashMap[c]--;
        }else{
            fuyin--;
        }
    }

    int countOfSubstrings(string word, int k) {
        int result = 0;
        int left = 0, right = 0;
        // [left,right]
        unordered_map<char, int> hashMap{{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int fuyin = 0;

        for(right=0;right < word.length();right++) {
            addChar(hashMap,fuyin,word[right]);
            while(isValid(hashMap,fuyin,k)){
                result++;
                delChar(hashMap,fuyin,word[left++]);
            }
        }
            

        return result;
    }
};
// @lc code=end

int main() {
    Solution sol;
    sol.countOfSubstrings("iqeaouqi", 2);
    return 0;
}