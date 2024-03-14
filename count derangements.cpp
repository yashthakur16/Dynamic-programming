#include<bits/stdc++.h>
#define MOD 1000000007
long long int solve(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }

    return (((n-1)%MOD)*((solve(n-1)%MOD)+((solve(n-2)%MOD))))%MOD;
}
long long int solveM(int n,vector<int>&dp)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]= (((n-1)%MOD)*((solveM(n-1,dp)%MOD)+((solveM(n-2,dp)%MOD))))%MOD;

    return dp[n];
}

long long int solveT(int n)
{
    vector<long long int >dp(n+1,0);
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++)
    {
        dp[i]=(((i-1)%MOD)*((dp[i-1]%MOD)+((dp[i-2]%MOD))))%MOD;
    }

    return dp[n];
}

long long int solveS(int n)
{
    long long int prev2=0;
    long long int prev1=1;
    long long int curr=0;

    for(int i=3;i<=n;i++)
    {
        curr=(((i-1)%MOD)*((prev1%MOD)+((prev2%MOD))))%MOD;
        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}



long long int countDerangements(int n) 
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }

    return solveS(n);
    //return solveT(n);
    //vector<int> dp(n+1,-1);
    //return solveM(n,dp);
    //return solve(n);
}
