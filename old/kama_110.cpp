#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    string beginStr,endStr;
    cin>>beginStr>>endStr;
    unordered_set<string> strSet;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        strSet.emplace(s);
    }
    unordered_map<string,int> strMap;
    queue<string> que;
    que.push(beginStr);
    strMap[beginStr]=1;
    while(!que.empty()){
        string word=que.front();
        que.pop();
        for(int i=0;i<word.size();i++){
            string newWord=word;
            for(int j=0;j<26;j++){
                newWord[i]='a'+j;
                if(newWord==endStr){
                    cout<<strMap[word]+1<<endl;
                    return 0;
                }
                if(strSet.find(newWord)!=strSet.end()&&
                   strMap.find(newWord)==strMap.end()){
                    strMap[newWord]=strMap[word]+1;
                    que.push(newWord);
                }
            }
        }
        
    }
    cout<<0<<endl;
    return 0;
}