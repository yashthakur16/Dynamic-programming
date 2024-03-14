#include <bits/stdc++.h>
#define MOD 1000000007


int solve(int n,int k)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return pow(k,2);
    }

    return (((((solve(n-2,k))%MOD)*(k-1)%MOD))+((((solve(n-1,k))%MOD)*(k-1))))%MOD;
}

int solveM(int n,int k,vector<int> &dp)
{
    if(n==1)
    {
        return dp[n]=k;
    }
    if(n==2)
    {
        return dp[n]=pow(k,2);
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]= ((solveM(n-2,k,dp))*(k-1))+((solveM(n-1,k,dp))*(k-1));

    return dp[n];
}

int solveT(int n,int k)
{
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=pow(k,2);

    for(int i=3;i<=n;i++)
    {
        dp[i]=((dp[i-2])*(k-1))+((dp[i-1])*(k-1));
    }

    return dp[n];
}

int solveS(int n,int k)
{
    
    int prev2=k;
    int prev1=pow(k,2);
    int curr;

    for(int i=3;i<=n;i++)
    {
        curr=((((prev2)%MOD)*((k-1)%MOD))+(((prev1)%MOD)*((k-1)%MOD)))%MOD;
        prev2=prev1;
        prev1=curr;
    }

    return prev1;

}

int numberOfWays(int n, int k) 
{
    
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return pow(k,2);
    }

    return solveS(n,k);


    //return solveT(n,k);
    // vector<int> dp(n+1,-1);
    // return solveM(n,k,dp);
   //return solve(n,k);
}
