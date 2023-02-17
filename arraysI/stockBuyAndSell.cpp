#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
int maxProfit(vector<int>&v){
    int n=v.size();
    int buy=INT_MAX;
    int profit=INT_MIN;
    for(int i=0; i<n; i++){
        if(buy>v[i]){
            buy=v[i];
        }else profit=max(profit, v[i]-buy);
    }
    return profit==INT_MIN?0:profit;
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<maxProfit(v);
    return 0;
}