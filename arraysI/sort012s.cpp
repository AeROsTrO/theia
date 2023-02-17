#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
void etTuBrute(vector<int>&v){
    sort(v.begin(), v.end());
    for(int i:v)cout<<i<<" ";
}
void better(vector<int>&v){
    int n=v.size(), z=0, o=0, t=0;
    for(int i=0; i<n; i++){
        if(v[i]==0)z++;
        else if(v[i]==1)o++;
        else t++;
    }
    int i=0;
    while(z--)v[i++]=0;
    while(o--)v[i++]=1;
    while(t--)v[i++]=2;
    for(int j:v)cout<<j<<" ";    
    //tc o(n) sc=O(1)
}
void optimal(vector<int>&v){
    int low=0, mid=0, high=v.size()-1;
    while(mid<=high){
        if(v[mid]==0){
            swap(v[low++], v[mid++]);
        }else if(v[mid]==1){
            mid++;
        }else swap(v[mid], v[high--]);
    }
    for(int i:v)cout<<i<<" ";
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    // etTuBrute(v);
    // better(v);
    optimal(v);
    return 0;
}