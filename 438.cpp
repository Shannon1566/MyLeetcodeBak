/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    bool isEmpty(vector<int>& hashMap){
        for(auto it:hashMap){
            if (it!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int left=0,right=p.size()-1;
        // [left,right]
        vector<int> result;
        if (s.size()<p.size()) return result;
        vector<int> hashMap(26,0);
        for(auto it:p){
            hashMap[it-'a']++;
        }
        for(int i=0;i<p.size();i++){
            hashMap[s[i]-'a']--;
        }

        while(right<s.size()){
            if(isEmpty(hashMap)) 
                result.emplace_back(left);
            hashMap[s[left]-'a']++;
            if(right+1>=s.size()) break;
            hashMap[s[right+1]-'a']--;
            left++;
            right++;
        }

        return result;
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.findAnagrams("cbaebabacd","abc");
    return 0;
}
