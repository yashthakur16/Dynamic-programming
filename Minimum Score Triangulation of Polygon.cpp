class Solution {
public:
    
    int solveM(vector<int>& values,int i,int j,vector<vector<int>> &dp)
    {
        if(i+1==j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        
        for(int k=i+1;k<j;k++)
        {
            ans=min(ans,values[i]*values[j]*values[k]+solveM(values,i,k,dp)+solveM(values,k,j,dp));
            dp[i][j]=ans;
        }
        return ans;
        
    }
    
    int SolveT(vector<int>& values)
    {
       int n=values.size();
        
       vector<vector<int>> dp(n,vector(n,0));
        
       
        for(int i=n-1;i>=0;i--) 
        {
            for(int j=i+2;j<n;j++)
            {
                 int ans=INT_MAX;
                for(int k=i+1;k<j;k++)
        {
            ans=min(ans,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
            dp[i][j]=ans;
        }
                
            }
        }
        
        return dp[0][n-1];
        
        
    }
               
    int minScoreTriangulation(vector<int>& values) 
    {
        
        
        return SolveT(values);
//         int i=0;
//         int j=values.size()-1;
        
//         vector<vector<int>> dp(j+2,vector(j+2,-1));
//         return solve(values,i,j,dp);
        
    }
};
