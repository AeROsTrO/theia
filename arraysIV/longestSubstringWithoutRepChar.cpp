#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given a string s, find the length of the longest substring without repeating characters.
int etTuBrute(string &s){
    int n=s.length();
    if(n==0 || n==1)return n;
    int i=0, j=0;
    int ans=0;
    int ind=0;
    unordered_map<char, int>m;
    while(j<n){
        m[s[j]]++;
        if(m.size()!=j-i+1){
            while(m.size()<j-i+1 && m.size())
            {if(--m[s[i]]==0)m.erase(s[i]);i++;}
           
        }
        else{
            if(ans<j-i+1){
                ind=i;
                ans=j-i+1;
            }
        }
        j++;
    }
    cout<<s.substr(ind, ans);
    return ans;
}
// better(){
// }
int optimal(string &s){
    unordered_map<int, int>m;
    int ans=0;
    for(int j=0,i=0; j<s.length(); j++){
        if(m[s[j]]>1){
            i=max(m[s[j]], i);
        }
        ans=max(ans, j-i+1);
        m[s[j]]=j+1;
    }
    return ans;
}
int main()
{
    string s;cin>>s;
    cout<<optimal(s);
    return 0;
}