#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
void etTuBrute(vector<int>&arr1, int m, vector<int>&arr2, int n){
    int j=0;
    for(int i=m; i<m+n; i++)arr1[i]=arr2[j++];
    sort(arr1.begin(),arr1.end());
}

void optimal(vector<int>&arr1, int m, vector<int>&arr2, int n){
    int i=m-1, j=n-1;
    int k=m+n-1;
    while(i>=0 && j>=0){
        if(arr1[i]>arr2[j]){
            arr1[k--]=arr1[i--];
        }else arr1[k--]=arr2[j--];
    }
    while(j>=0)arr1[k--]=arr2[j--];
}
int main()
{
    int m, n;cin>>m>>n;
    vector<int>arr1(n+m), arr2(n);
    for(int i=0; i<m; i++)cin>>arr1[i];
    for(int i=0; i<n; ++i)cin>>arr2[i];
    optimal(arr1, m, arr2, n);
    for(int i:arr1)cout<<i<<" ";
    return 0;
}