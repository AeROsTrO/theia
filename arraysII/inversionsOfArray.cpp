#include <bits/stdc++.h>
using namespace std;
//problem description here
// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
int etTuBrute(vector<int>&v){
    int ct=0;
    int n=v.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)if(v[j]<v[i])++ct;
    }
    return ct;
}
int merge(vector<int>&v, int low, int mid, int high){
    int ct=0;
    int j=mid+1;
    for(int i=low; i<=mid; i++){
        while(j<=high && v[j]<v[i])++j;
        ct+=j-(mid+1);
    }
    vector<int>t;
    int i=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(v[i]<v[j])t.push_back(v[i++]);
        else t.push_back(v[j++]);
    }
    while(i<=mid)t.push_back(v[i++]);
    while(j<=high)t.push_back(v[j++]);
    for(int k=low; k<=high; k++)v[k]=t[k-low];
    return ct;
}
int mergeSort(vector<int>&v, int low, int high){
    if(low>=high)return 0;
    int mid=(low+high)/2;
    int ct=0;
    ct+=mergeSort(v, low, mid);
    ct+=mergeSort(v, mid+1, high);
    ct+=merge(v, low, mid, high);
    return ct;
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<etTuBrute(v)<<endl<<mergeSort(v, 0, n-1);
    return 0;
}