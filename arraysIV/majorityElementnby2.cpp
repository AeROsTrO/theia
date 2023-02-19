#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

int etTuBrute(vector<int>&v){
    int n=v.size();
    sort(v.begin(), v.end());
    int ct=1;int ele=-1;
    for(int i=0; i<n-1; i++){
        if(v[i]==v[i+1])++ct;
        else{
            if(ct>n/2){
                ele=v[i];
            }
            ct=1;
        }
    }
    if(ct>n/2)ele=v[n-1];
    return ele;

}
int better(vector<int>&v){
     unordered_map<int, int>m;
     int n=v.size();
    for(int i=0; i<n; i++){ 
        m[v[i]]++;
    }
    for(auto p:m)if(p.second>n/2)return p.first;
    return -1;
}
int optimal(vector<int>&v){
    int count=0;
    int ele=-1;
    for(int i:v){
        if(count==0){
            ele=i;
        }
        if(ele==i)++count;
        else --count;
    }
    count=0;
    for(int i:v)if(i==ele)++count;
    int n=v.size();
    return count>n/2?ele:-1;
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<etTuBrute(v)<<endl<<better(v)<<endl<<optimal(v);
    return 0;
}