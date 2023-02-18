#include <bits/stdc++.h>
# using namespace std;
#problem description here
# // Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).
def etTuBrute(x, exp):
    ans=1.0
    x=float(x)
    exp=int(exp)
    for i in range(0,exp):
        ans*=x
    return ans;
# O(n)
def bin_exp(x, exp) ->float:
    x=float(x)
    if nn<0:
        nn=-1*nn
    ans=1.0
    nn=float(exp)
    while nn:
        if nn%2!=0:
            ans=ans*x
            nn=nn-1
        else:
            x=x*x
            nn//=2
    if n<0:
        ans=1.0/ans
    return ans
# O(logn)
   
n=input("enter number:")
exp=input("enter exponent:")
n=float(n)
exp=float(exp)
print(bin_exp(n, exp))  
# print(etTuBrute(n, exp))  

