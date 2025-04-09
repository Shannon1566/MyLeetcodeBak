#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int sLength=s.length();
        int numCnt=0;
        for(int i=0;i<sLength;i++){
            if(s[i]>='0'&&s[i]<='9') numCnt++;
        }
        s.resize(sLength+numCnt*(6-1));
        int tailOld=sLength-1;
        int tailNew=s.length()-1;
        while(tailOld>=0){
            if (s[tailOld]>='0'&&s[tailOld]<='9'){
                s[tailNew--] = 'r';
                s[tailNew--] = 'e';
                s[tailNew--] = 'b';
                s[tailNew--] = 'm';
                s[tailNew--] = 'u';
                s[tailNew--] = 'n';
            }else{
                s[tailNew--] = s[tailOld];
            }
            tailOld--;
        }
        cout<<s<<endl;
    }
}