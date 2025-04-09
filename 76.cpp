/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "0.cpp"
// @lc code=start
class Solution {
    bool isValid(unordered_map<char,int>& hashMap){
        for(auto it:hashMap){
            if(it.second>0) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hashMap;
        for(int i=0;i<t.size();i++){
            hashMap[t[i]]++;
        }
        int head=0;
        int tail=0;
        int minLength=INT32_MAX;
        int resultHead=0;
        int resultTail=0;
        // [head,tail]
        for(tail=0;tail<s.size();tail++){
            if(hashMap.find(s[tail])!=hashMap.end()){
                hashMap[s[tail]]--;
            }
            while(isValid(hashMap)){
                if(minLength>tail-head+1){
                    minLength=tail-head+1;
                    resultHead=head;
                    resultTail=tail;
                }
                if(hashMap.find(s[head])!=hashMap.end()){
                    hashMap[s[head]]++;
                }
                head++;
            }
            
        }
        if(minLength==INT32_MAX) return "";
        return s.substr(resultHead,minLength);
    }
};
// @lc code=end

int main() {
    // 测试代码

    Solution solution;


    // 调用解题函数并输出结果
    cout<<solution.minWindow("a","aa")<<endl;


    return 0;
}