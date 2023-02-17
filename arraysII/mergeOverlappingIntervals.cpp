#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

void optimal(vector<vector<int>>&v){
    vector<vector<int>>ans;
    int n=v.size();
    for(int i=0; i<n; i++){
        if(ans.empty())ans.push_back(v[i]);
        else{
            if(ans.back().back()>=v[i][0])ans.back().back()=v[i][1];
            else ans.push_back(v[i]);
        }
    }
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
int n;
cin>>n;
vector<vector<int>>v(n, vector<int>(2));
for(int i=0; i<n; i++)cin>>v[i][0]>>v[i][1];
optimal(v); 
return 0;
}