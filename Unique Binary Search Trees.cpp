class Solution {
public:
    
     int solveT(int p)
    {
         vector<int>dp(p+1,0);
         dp[0]=1;
         dp[1]=1;
        
        for(int n=1;n<=p;n++)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                ans+=dp[i-1]*dp[n-i];
            }

            dp[n]=ans;    
        }
        
        
        
        return dp[p];
    }
    
    int solve(int n, vector<int> &dp)
    {
         if(n<=1)
            return 1;
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=0;
        
        
        
        for(int i=1;i<=n;i++)
        {
            ans+=solve(i-1,dp)*solve(n-i,dp);
        }
        
        dp[n]=ans;
        
        return dp[n];
    }
    int numTrees(int n) 
    {
       //  vector<int> dp(n+1,-1);
       // return solve(n,dp);
        
        return solveT(n);
    }
};
