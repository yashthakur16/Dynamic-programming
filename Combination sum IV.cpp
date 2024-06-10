#include <bits/stdc++.h> 


int solve(vector<int> &num,int target,vector<int> &dp)
{
    if(target<0)
    {
        return 0;
    }
    if(target==0)
    {
        return 1;
    }
    if(dp[target]!=-1)
    {
        return dp[target];
    }

    int total=0;

    for(int i=0;i<num.size();i++)
    {
        total=total+solve(num,target-num[i],dp);

    }
    dp[target]=total;

    return dp[target];
}

int solveT(vector<int> &num,int target)
{
    vector<int> dp(target+1,0);
    dp[0]=1;


    for(int i=0;i<=target;i++)
    {
        for (int j = 0; j < num.size(); j++) 
        {
            if(i-num[j]>=0)
            dp[i]= dp[i]+ dp[i - num[j]];
        }
    }

   

    return dp[target];
}



int findWays(vector<int> &num, int tar)
{
    return solveT(num,tar);
    // vector<int> dp(tar+1,-1);
    // return solve(num,tar,dp);
}
