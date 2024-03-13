#include <bits/stdc++.h> 

int solve(vector<int> &nums,int i,vector<int> &dp)
{

    if(i>nums.size()-1)
    {
        return 0;
    }
      if(i==nums.size()-1)
    {
        return nums[i];
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    
    int include=nums[i]+solve(nums,i+2,dp);
    int exclude=solve(nums,i+1,dp);
    dp[i]=max(include,exclude);

    return dp[i];

}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp(n,-1);
   int ans=max(solve(nums,0,dp),solve(nums,1,dp));

   return ans;
}
