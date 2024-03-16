#include <bits/stdc++.h>

int solve(vector<int> &weight, vector<int> &value, int i, int maxWeight,int n)
{
	if(i==n-1)
	{
		if(weight[i]<=maxWeight)
		{
			return value[i];
		}
		else
		{
			return 0;
		}
		
	}

	int ans1=0;
	int ans2=0;

	if(weight[i]<=maxWeight)
	ans1=value[i]+solve(weight,value,i+1,maxWeight-weight[i],n);
	
	ans2=solve(weight,value,i+1,maxWeight,n);

	int ans=max(ans1,ans2);

	return ans;



}

int solveM(vector<int> &weight, vector<int> &value, int i, int maxWeight,int n,vector<vector<int>> &dp)
{
	if(i==n-1)
	{
		if(weight[i]<=maxWeight)
		{
			dp[i][maxWeight]= value[i];
		}
		else
		{
			dp[i][maxWeight]= 0;
		}
		
	}

	if(dp[i][maxWeight]!=-1)
	{
		return dp[i][maxWeight];
	}

	int ans1=0;
	int ans2=0;

	if(weight[i]<=maxWeight)
	ans1=value[i]+solveM(weight,value,i+1,maxWeight-weight[i],n,dp);
	
	ans2=solveM(weight,value,i+1,maxWeight,n,dp);

	dp[i][maxWeight]=max(ans1,ans2);

	return dp[i][maxWeight];



}


int solveT(vector<int> &weight, vector<int> &value, int maxWeight,int n)
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	for(int w=0;w<=maxWeight;w++)
	{
		if(weight[n-1]<=w)
		{
			dp[n-1][w]= value[n-1];
		}
		
	}

	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<=maxWeight;j++)
		{
			int ans1=0;
			int ans2=0;

			if(weight[i]<=j)
			ans1=value[i]+dp[i+1][j-weight[i]];
			
			ans2=dp[i+1][j];

			dp[i][j]=max(ans1,ans2);
		}
		
	}
	

	return dp[0][maxWeight];



}

int solveS(vector<int> &weight, vector<int> &value, int maxWeight,int n)
{
	vector<int> prev(maxWeight+1,0);
	vector<int> curr(maxWeight+1,0);
	for(int w=0;w<=maxWeight;w++)
	{
		if(weight[n-1]<=w)
		{
			prev[w]= value[n-1];
		}
		
	}

	for(int i=n-2;i>=0;i--)
	{
		curr=prev;
		for(int j=0;j<=maxWeight;j++)
		{
			int ans1=0;
			int ans2=0;

			if(weight[i]<=j)
			ans1=value[i]+prev[j-weight[i]];
			
			ans2=prev[j];

			curr[j]=max(ans1,ans2);
		}
		prev=curr;
		
	}
	

	return prev[maxWeight];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveS(weight,value,maxWeight,n);
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	// return solveM(weight,value,0,maxWeight,n,dp);
}
