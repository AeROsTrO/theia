#include <bits/stdc++.h>
using namespace std;
//problem description here
pair<int, int> better(vector<int>&v){
    int n=v.size();
    sort(v.begin(), v.end());
    int ele1=0, ele2=0, cnt=1;
    for(int i=0; i<n-1; i++){
        if(v[i]==v[i+1]){cnt++;}
        else{
            if(cnt>n/3){
                if(ele1==0)ele1=v[i];
                else ele2=v[i];
                cnt=1;
            }
        }
    }    
    if(ele1==0)ele1=v[n-1];
    else ele2=v[n-1];
    return {ele1, ele2};
    //O(nlogn) O(1)
}
pair<int, int> etTuBrute(vector<int>&v){
    map<int, int>m;
    int n=v.size();
    for(int i:v)m[i]++;
    pair<int, int>p{-1, -1};
    for(auto i:m)if(i.second>n/3){
        if(p.first==-1)p.first=i.first;
        else p.second=i.first;
    }
    return p;
    //O(nlogn) O(n)
}
pair<int, int> optimal(vector<int>&v){
    //boyre moore voting algorithm
    //an array can have atmost 2 majority elements:
    //n/3+x+n/3+y+z(remaining elements total freq)=n
    //2*n/3+x+y+z=n
    //x+y+z=n/3
    //z=n/3-(x+y)
    //so there is no way that we can have another element whose frequency is more than n/3
    int c1=0, c2=0, ele1=INT_MAX, ele2=INT_MAX;
    int n=v.size();
    for(int i=0; i<n; i++){
        if(v[i]==ele1)c1++;
        else if(v[i]==ele2)c2++;
        else if(c1==0){
            ele1=v[i];
            c1=1;
        }
        else if(c2==0){
            ele2=v[i];
            c2=1;
        }
        else c1--, c2--;
    }
    c1=0;
    for(int i:v){
        if(i==ele1)c1++;
        if(i==ele2)c2++;
    }
   if(c1>n/3 && c2>n/3)return {ele1, ele2};else return {-1, -1};
   //O(n) O(1)
}
void print(pair<int, int>&p){
    cout<<p.first<<" "<<p.second<<endl;
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    pair<int, int>ans;
    ans=etTuBrute(v);
    print(ans);
    ans=better(v);
    print(ans);
    ans=optimal(v);
    print(ans);
    return 0;
}