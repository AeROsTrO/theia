#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.
int etTuBrute(int x, int y, int rows, int cols){
    
    if(x>=rows || y>=cols)return 0;
    if(x==rows-1 && y==cols-1)return 1;
    int right=etTuBrute(x+1, y, rows ,cols);
    int down=etTuBrute(x, y+1, rows, cols);
    return right+down;
}
int better(int x, int y, int m, int n, vector<vector<int>>&dp){
    if(x>=m || y>=n)return 0;
    if(x==m-1 && y==n-1)return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    return dp[x][y]=better(x+1, y, m , n, dp)+better(x, y+1, m, n, dp);
}
//grid unique paths
int rec(int i, int j)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = rec(i - 1, j);
    int left = rec(i, j - 1);
    return up + left;
}
int recMemo(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return dp[i][j] = 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = recMemo(i - 1, j, dp), left = recMemo(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int tab(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    // dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = 1;
            else
            {
                int up = i ? dp[i - 1][j] : 0;
                int left = j ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int tabSpaceOpt(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, -1);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
                temp[j] = 1;
            else
            {
                int up = i ? prev[j] : 0;
                int left = j ? temp[j - 1] : 0;
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[n - 1];
}
int main()
{
    int m=3, n=7;
    cout<<etTuBrute(0, 0, m, n);
    vector<vector<int>>v(m, vector<int>(n, -1));
    cout<<better(0, 0, m, n, v);
    return 0;
}