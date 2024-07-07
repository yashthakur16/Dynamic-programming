class Solution {
public:
    
     int solveT(int p)
    {
        vector<vector<int>> dp(p+3,vector<int>(p+3,0));
        
         
         for(int index=p;index>=1;index--)
         {
             for(int n=index;n<=p;n++)
             {
                 if(index==n)
                 {
                     continue;
                 }
                 else
                 {
                     int ans=INT_MAX;

                    for(int i=index;i<=n;i++)
                    {
                        ans=min(ans,i+max(dp[index][i-1],dp[i+1][n]));
                    }

                    dp[index][n]=ans;
                 }
                 
             }
         }
        
        return dp[1][p];
    }
    
    int solveM(int index,int n,vector<vector<int>>&dp)
    {
        if(index>=n)
        {
            return 0;
        }
        
        if(dp[index][n]!=-1)
        {
            return dp[index][n];
        }
        
        int ans=INT_MAX;
        
        for(int i=index;i<=n;i++)
        {
            ans=min(ans,i+max(solveM(index,i-1,dp),solveM(i+1,n,dp)));
        }
        
        dp[index][n]=ans;
        return dp[index][n];
    }
    
    int solve(int index,int n)
    {
        if(index>=n)
        {
            return 0;
        }
        
        int ans=INT_MAX;
        
        for(int i=index;i<=n;i++)
        {
            ans=min(ans,i+max(solve(index,i-1),solve(i+1,n)));
        }
        
        return ans;
    }
    int getMoneyAmount(int n) {
        // return solve(1,n);
        
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
//         return solveM(1,n,dp);
        
        return solveT(n);
    }
};
