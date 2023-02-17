#include <bits/stdc++.h>
using namespace std;
//problem description here

vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1)return ans;
        ans.push_back({1, 1});
        if(numRows==1)return ans;
        for(int i=2; i<numRows; i++){
            vector<int>line;
            line.push_back(1);
            for(int j=1; j<ans.back().size(); j++){
                line.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            line.push_back(1);
            ans.push_back(line);
        }
        return ans;
}
int main()
{
 
return 0;
}
