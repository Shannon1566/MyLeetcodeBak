#include<iostream>
using namespace std;
void reverse(string& s,int head,int tail){
    while(head<tail){
        int temp=s[tail];
        s[tail]=s[head];
        s[head]=temp;
        head++;
        tail--;
    }
}
int main(){
    int k;
    string s;
    cin>>k;
    cin>>s;
    int sLength=s.length();
    reverse(s,0,sLength-1);
    reverse(s,0,k-1);
    reverse(s,k,sLength-1);
    cout<<s<<endl;
    return 0;
}