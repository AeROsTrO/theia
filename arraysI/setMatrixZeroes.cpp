#include <bits/stdc++.h>
using namespace std;
//problem description here

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
void sett(vector<vector<int>>&v, int row, int col){
    int rows=v.size(), cols=v[0].size();
    for(int j=0; j<cols; j++)v[row][j]=0;
    for(int i=0; i<rows; i++)v[i][col]=0;

}
void etBrute(vector<vector<int>>v){
    vector<pair<int, int>>pairs;
    int rows=v.size(), cols=v[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(v[i][j]==0)pairs.push_back({i, j});
        }
    }
    for(int i=0; i<pairs.size(); i++)sett(v, pairs[i].first, pairs[i].second);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); ++j)cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
void better(vector<vector<int>>v)
{
    set<int>rowv, colv;
    int rows=v.size(), cols=v[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(v[i][j]==0)rowv.insert(i), colv.insert(j);
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(rowv.find(i)!=rowv.end() || colv.find(j)!=colv.end())v[i][j]=0;
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); ++j)cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
void optimal(vector<vector<int>>v){
    int rows=v.size(), cols=v[0].size();
    bool fr=false, fc=false;
    for(int j=0; j<cols; j++){
        if(v[0][j]==0){fr=true;break;}
    }
    for(int i=0; i<rows; i++)if(v[i][0]==0){fc=true;break;}
    for(int i=1; i<rows; i++){
        for(int j=1; j<cols; j++){
            if(v[i][j]==0){
                v[i][0]=0;
                v[0][j]=0;
            }
        }
    }
    for(int i=1; i<rows; i++){
        for(int j=1; j<cols; j++){
            if(v[i][0]==0 || v[0][j]==0){
                v[i][j]=0;
            }
        }
    }
    if(fr){
        for(int i=0; i<cols; i++){
            v[0][i]=0;
        }
    }
    if(fc){
        for(int i=0; i<rows; i++)v[i][0]=0;
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); ++j)cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int m, n;cin>>m>>n;
    vector<vector<int>>v(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)cin>>v[i][j];
    }
    // better(v);
    // etBrute(v);
    optimal(v);
    return 0;
}