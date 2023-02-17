#include <bits/stdc++.h>
using namespace std;
//problem description here
//you are given an array of integers containing n elements, each integer is in the range [1, n-1] with exactly one element in the array
//your task is to find duplicate element, the duplicate element may be repeated more than twice in the array but there will be exactly one element that is repeated in the array.
int etTuBrute(vector<int>&v){
    int x=-1;
    sort(v.begin(), v.end());
    int n=v.size();
    for(int i=0; i<n; i++)if(v[i]==v[i+1])x=v[i];
    return x;
    //O(nlogn) O(1)
}
int better(vector<int>&v){
    unordered_map<int, int>m;
    for(int i:v)m[i]++;
    for(auto p:m)if(p.second>1)return p.first;
    return -1;
    //O(n) o(n)
}
int optimal(vector<int>&v){
   int n=v.size();
   int i=0;
   while(i<n){
    if(v[i]==-1)return i;
    int next=v[i];
    v[i]=-1;
    i=next;
   }
   return -1;
    //O(n) O(1)
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<etTuBrute(v);
    return 0;
}