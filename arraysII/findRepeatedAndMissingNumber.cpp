#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.
void etTuBrute(vector<int>&v){
    int n=v.size();
    unordered_map<int, int>m;
    int ans1=-1, ans2=-1;
    for(int i=1; i<=n; i++)m[i]=0;
    for(int i=0; i<n; i++)m[v[i]]++;
    for(auto p:m){if(p.second==0)ans1=p.first;
    if(p.second>1)ans2=p.first;
    }
    cout<<"missing: "<<ans1<<" repeating: "<<ans2<<endl;
    //o(n) o(n)
}
void better(vector<int>&v){
    int n=v.size();
    int sumel=accumulate(v.begin(), v.end(), sumel);
    int sumsq=0;
    for(int i:v)sumsq+=i*i;
    int sumi=0, sqi=0;
    for(int i=1; i<=n; i++)sumi+=i;
    for(int i=1; i<=n;i++)sqi+=i*i;
    int x=sumi-sumel;
    int y=sqi-sumsq;
    int z=y/x;
    int ans1=(x+z)/2;
    cout<<"missing: "<<ans1;
    cout<<"\nrepeating: "<<abs(x-ans1);
}
int optimal(vector<int>&v){
    int n=v.size();
    int slow=v[0], fast=v[0];
    while(1){
        slow=v[slow];
        fast=v[v[fast]];
        if(slow==fast)break;
    }
    int ptr1=v[0],ptr2=slow;
    while(ptr1!=ptr2){
        ptr1=v[ptr1];
        ptr2=v[ptr2];
    } 
    int dup=ptr1;
    printf("repeated: %d\n", ptr1);
    int xr1=0, xr2=dup;
    for(int i=1; i<=n; i++)xr1^=i;
    for(int i=0; i<n; i++)xr2^=v[i];
    return xr1^xr2;
    //o(n) O(1)
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    better(v);
    return 0;
}