#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.
bool etTuBrute(vector<vector<int>>&v, int k){
    int rows=v.size(), cols=v[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++)if(v[i][j]==k)return true;
    }
    return false;
    //O(m*n) O(1)
}
bool better(vector<vector<int>>&v, int k){
     int rows=v.size(), cols=v[0].size();
    for(int i=0; i<rows;i++){
        if(v[i][cols-1]<k)continue;
        for(int j=0; j<cols; j++)if(v[i][j]==k)return true;
    }
    return false;
    //O(n) o(1)
}
bool optimal(vector<vector<int>>&v, int k){
int rows=v.size(), cols=v[0].size();
    int i=0, j=cols-1;
    while(i<rows && cols>=0){
        if(v[i][j]>k)j--;
        else if(v[i][j]<k)i++;
        else return true;
    }
    return false;
    // O(n) O(1)
}
bool moreOptimal(vector<vector<int>>&v, int k){
    int rows=v.size(), cols=v[0].size();
    int low=0, high=(cols*rows)-1;
    while(low<=high){
        int mid=(low+(high-low)/2);
        int r=mid/cols, c=mid%cols;
        if(v[r][c]==k)return true;
        else if(v[r][c]<k)low=mid+1;
        else high=mid-1;
    }
    return false;
    //O(log(n*m)) O(1)
}
int main()
{
    int rows, cols;cin>>rows>>cols;
    vector<vector<int>>v(rows, vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++)cin>>v[i][j];
    }
    int k;cin>>k;
    cout<<etTuBrute(v, k)<<endl;
    cout<<better(v, k)<<endl;
    cout<<optimal(v, k)<<endl;
    cout<<moreOptimal(v, k)<<endl;
    return 0;
}