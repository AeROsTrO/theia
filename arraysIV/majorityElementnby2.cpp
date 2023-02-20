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
    //explains well: https://youtu.be/7pnhv842keE
    //The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.
    // Majority element count = N/2 + x;
    // Minority/Other elements = N/2 – x;
    // Where x is the number of times it occurs after reaching the minimum value N/2.
    // Now, we can say that count of minority elements and majority elements are equal up to a certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 
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