#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.
int etTuBrute(vector<int>&v){
    int n=v.size();
    int sum=0;
    int max_sum=INT_MIN;
    for(int i=0; i<n; i++){
        sum=0;
        for(int j=i; j<n; j++){
            sum+=v[j];
            if(sum>max_sum)max_sum=sum;
        }
    }
    //tc, sc=O(n^2), O(1)
    return max_sum;
}
int optimal(vector<int>&v){
    //kadane's algo
    //at every subarray maintain a variable that stores the value of the previous subarray and after adding every element check if its sum is greater than the previous variable
    //assumption:sum of an empty subarray is 0
    int n=v.size();
    int curr_sum=0, max_sum=0;
    for(int i=0; i<n; i++){
        curr_sum=max(curr_sum+v[i], v[i]);
        max_sum=max(max_sum, curr_sum);
    }
    return max_sum<0?0:max_sum;

    //tc, sc=O(n), O(1)
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    // cout<<etTuBrute(v);
    cout<<optimal(v);
    return 0;
}