# Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.
def etTuBrute(x: list, k: int)->bool:
    for i in range(0, len(x)):
        for j in range(i+1, len(x)):
            if x[i]+x[j]==k:
                return True;
    return False;
# O(n^2)
def better(x:list, k:int)->bool:
    x=sorted(x)
    l=0
    r=len(x)-1
    while l<r:
        if x[l]+x[r]<k:
            l=l+1
        elif x[l]+x[r]>k:
            r=r-1
        else:
            return True
    return False 
# O(nlogn) o(1)
def optimal(x:list, k:int)->bool:
    mp={}
    res=[]
    for i in range(0, len(x)):
        if (k-x[i]) in mp:
            res.append(i)
            res.append(mp[k-x[i]])
            return res
        mp[x[i]]=i
    return res
# o(n) o(n)
x=[1, 6, 3, 2, 5]
k=8
# print(etTuBrute(x, k))
# print(better(x, k))
print(optimal(x, k))