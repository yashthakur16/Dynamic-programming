class Solution {
public:
    
    int solveS(string &text1,string &text2)
    {
       vector<int> curr(text2.size()+1,0);
        vector<int> next(text2.size()+1,0);
        
        for(int i=text1.size()-1;i>=0;i--)
        {
            for(int j=text2.size()-1;j>=0;j--)
            {
                
                if(text1[i]==text2[j])
                {
                    curr[j]= 1+next[j+1];
                    
                }
                else
                {
                    curr[j]= max(next[j],curr[j+1]);
                   
                }
            }
            next=curr;
        }
        
        return next[0];
    }
    
    int solveT(string &text1,string &text2)
    {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        
        for(int i=text1.size()-1;i>=0;i--)
        {
            for(int j=text2.size()-1;j>=0;j--)
            {
                
                if(text1[i]==text2[j])
                {
                    dp[i][j]= 1+dp[i+1][j+1];
                    
                }
                else
                {
                    dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
                   
                }
            }
        }
        
        return dp[0][0];
    }
    
    
    
    int solveM(string &text1,string &text2,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=text1.size()||j>=text2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=0;
        
        if(text1[i]==text2[j])
        {
            ans= 1+solveM(text1,text2,i+1,j+1,dp);
            
        }
        else
        {
            ans= max(solveM(text1,text2,i+1,j,dp),solveM(text1,text2,i,j+1,dp));
           
        }
        
        dp[i][j]=ans;
        return dp[i][j];
        
    }

    int solve(string text1,string text2,int i,int j)
    {
        if(i>=text1.size()||j>=text2.size())
        {
            return 0;
        }
        
        if(text1[i]==text2[j])
        {
            return 1+solve(text1,text2,i+1,j+1);
        }
        else
        {
            return max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        // return solve(text1,text2,0,0);
        
//         vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
//         return solveM(text1,text2,0,0,dp);
        
      // return solveT(text1,text2);
        return solveS(text1,text2);
        
    }
};
