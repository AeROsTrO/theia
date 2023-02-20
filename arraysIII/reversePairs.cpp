#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
int etTuBrute(vector<int>&v){
    int n=v.size();
    int ct=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]>2*v[j])++ct;
        }
    }
    return ct;
}
int merge(vector<int>&v, int low, int mid, int high){
    int n=v.size();
    int total=0;
    int j=mid+1;
    for(int i=low; i<=mid; i++){
        while(j<=high && v[i]>2*v[j])++j;
        total+=j-(mid+1);
    }
    int i=low;j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=high){
        if(v[i]<=v[j])temp.push_back(v[i++]);
        else temp.push_back(v[j++]);
    }
    while(i<=mid)temp.push_back(v[i++]);
    while(j<=high)temp.push_back(v[j++]);
    for(int k=low; k<=high; k++)v[k]=temp[k-low];
    return total;
}
int mergeSort(vector<int>&v, int low, int high){
    if(low>=high)return 0;
    int mid=(low+high)>>1;
    int invCnt=0;
    invCnt+=mergeSort(v, low, mid)+mergeSort(v, mid+1, high)+merge(v, low, mid, high);
    return invCnt;
}
int optimal(vector<int>&v){
    return mergeSort(v, 0, v.size()-1);
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<etTuBrute(v)<<endl<<optimal(v);
    return 0;
}