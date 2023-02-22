#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
int etTuBrute(vector<int>&v){
    int n=v.size();
    sort(v.begin(), v.end());
    int len=1;int maxlen=0;
    for(int i=0; i<n-1; i++){
        if(v[i]==v[i+1]-1)len++;
        else{
            maxlen=max(maxlen, len);
            len=1;
        }
    }
    return maxlen=max(len, maxlen);
}
int better(vector<int>&v){
    int n=v.size();
    set<int>s;
    for(int i:v)s.insert(i);
    int maxlen=0;
    for(int i:v){
        if(s.find(i-1)==s.end()){
            int currnum=i;
            int currlen=1;
            while(s.find(currnum+1)!=s.end()){
                currnum++;
                currlen++;
            }
            maxlen=max(currlen, maxlen);
        }
    }
    return maxlen;
}
// optimal(){
// }
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<etTuBrute(v)<<endl<<better(v);
    return 0;
}