/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    vector<string> result;
    string path;
    void backtracing(string&s,int begin){
        if(path.length()==s.length()){
            result.emplace_back(path);
            return;
        }
        
        int num=(int)(s[begin]-'0');
        for(int i=0;i<letterMap[num].length();i++){
            path+=(letterMap[num][i]);
            backtracing(s,begin+1);
            path.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return result;
        int length=digits.length();
        backtracing(digits,0);
        return result;
    }
};
// @lc code=end
int main(){
    Solution sol;
    sol.letterCombinations("23");
    return 0;
}