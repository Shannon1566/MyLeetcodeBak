/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "0.cpp"
// @lc code=start
class Solution {
public:
    
    bool hasWord(string& s,int head,int tail ,vector<string>& wordDict){
        string str=s.substr(head,tail-head+1);
        auto it =find(wordDict.begin(),wordDict.end(),str);
        if(it!=wordDict.end()) return true;
        else return false;
    }
    bool backtracking(string& s, vector<string>& wordDict,int startIndex,vector<bool>& memory){
        if(startIndex>=s.size()){
            return true;
        }
        if(memory[startIndex]==false) return memory[startIndex];
        for(int i=startIndex;i<s.size();i++){
            if(hasWord(s,startIndex,i,wordDict)&&backtracking(s,wordDict,i+1,memory)){
                return true;
            }
        }
        memory[startIndex] =false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memory(s.size(),true);
        return backtracking(s,wordDict,0,memory);
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<string> wordDict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",wordDict);
    cout<<sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",wordDict)<<endl;
    return 0;
}
