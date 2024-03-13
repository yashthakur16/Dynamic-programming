#include <bits/stdc++.h> 

long long int solve(vector<int> arr)
{
    long long int n=arr.size();
    if(n==1)
    {
        return arr[0];
    }
    if(n==0)
    {
        return 0;
    }

    long long int prev1=0;
    long long int prev=arr[0];

    for(int i=1;i<n;i++)
    {
        long long int rob=arr[i]+prev1;
        long long int norob=prev;
        long long int ans=max(rob,norob);
        prev1=prev;
        prev=ans;
    }

    return prev;

}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 0) return 0;
    if (n == 1) return valueInHouse[0];
    vector<int> first,second;

    for(int i=0;i<valueInHouse.size()-1;i++)
    {
        first.push_back(valueInHouse[i]);
    }

    for(int i=1;i<valueInHouse.size();i++)
    {
        second.push_back(valueInHouse[i]);
    }

    return max(solve(first),solve(second));
}
