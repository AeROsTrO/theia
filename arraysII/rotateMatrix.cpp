#include <bits/stdc++.h>
using namespace std;
// problem description here
void print(vector<vector<int>> &v)
{
    int rows = v.size(), cols = v[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void brute(vector<vector<int>> v)
{
    int rows = v.size(), cols = v[0].size();
    vector<vector<int>>rot(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            rot[j][cols-i-1]=v[i][j];
        }
    }
    print(rot);
}
void optimal(vector<vector<int>> v)
{
    int rows = v.size(), cols = v[0].size();
    reverse(v.begin(), v.end());

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j > i)
                swap(v[i][j], v[j][i]);
        }
    }
    print(v);
}
void optimall(vector<vector<int>> v)
{
    int rows = v.size(), cols = v[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<i; i++)swap(v[i][j], v[j][i]);
    }
    for(int i=0; i<rows; i++)reverse(v[i].begin(), v[i].end());
    print(v);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    brute(v);
    optimal(v);
    optimall(v);
    return 0;
}