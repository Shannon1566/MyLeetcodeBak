#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int numCnt=0;
    for(char ch:s){
        if(ch>='0'&&ch<='9'){
            numCnt++;
        }
    }
    int left=s.size()-1;
    s.resize(s.size()+numCnt*5);
    int right=s.size()-1;
    while(left>0){
        if(s[left]>='0'&&s[left]<='9'){
            s[right--]='r';
            s[right--]='e';
            s[right--]='b';
            s[right--]='m';
            s[right--]='u';
            s[right--]='n';
        }else{
            s[right--]=s[left];
        }
        left--;
    }
    cout<<s<<endl;
    return 0;
}