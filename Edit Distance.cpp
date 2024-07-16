class Solution {
public:
    
     int solveS(string &w1,string &w2)
    {

         vector<int> curr(w2.size()+1,0);
         vector<int> next(w2.size()+1,0); 
         
         
        for(int i=0;i<w2.length();i++)
        {
           next[i]=w2.length()-i;
        }
        
      
        for(int i=w1.size()-1;i>=0;i--)
        {
            for(int j=w2.size()-1;j>=0;j--)
            {
                
                curr[w2.length()]=w1.length()-i;
                
                
                int ans=0;

                if(w1[i]==w2[j])
                {
                       curr[j]= next[j+1];
                }
                else
                {

                    int insert=1+curr[j+1];
                    int del=1+next[j];
                    int replace=1+next[j+1];

                    ans=min(insert,min(del,replace));
                    curr[j]=ans;
                }

            }
            
            next=curr;
        }
        
        
        return next[0];
    }
    
    
    
    int solveT(string &w1,string &w2)
    {
         vector<vector<int>> dp(w1.size()+2,vector<int>(w2.size()+2,0));
        
        for(int i=0;i<w2.length();i++)
        {
            dp[w1.length()][i]=w2.length()-i;
        }
        
         for(int i=0;i<w1.length();i++)
        {
            dp[i][w2.length()]=w1.length()-i;
        }
        
        for(int i=w1.size()-1;i>=0;i--)
        {
            for(int j=w2.size()-1;j>=0;j--)
            {
                int ans=0;

                if(w1[i]==w2[j])
                {
                       dp[i][j]= dp[i+1][j+1];
                }
                else
                {

                    int insert=1+dp[i][j+1];
                    int del=1+dp[i+1][j];
                    int replace=1+dp[i+1][j+1];

                    ans=min(insert,min(del,replace));
                    dp[i][j]=ans;
                }

            }
        }
        
        
        return dp[0][0];
    }
    
    
    int solveM(string &w1,string &w2,int i,int j,vector<vector<int>> &dp)
    {
        
        if(i==w1.length())
        {
            return w2.length()-j;
        }
        
        if(j==w2.length())
        {
            return w1.length()-i;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=0;
        
        if(w1[i]==w2[j])
        {
               dp[i][j]= solveM(w1,w2,i+1,j+1,dp);
            return dp[i][j];
        }
        else
        {
            
            int insert=1+solveM(w1,w2,i,j+1,dp);
            int del=1+solveM(w1,w2,i+1,j,dp);
            int replace=1+solveM(w1,w2,i+1,j+1,dp);
            
            ans=min(insert,min(del,replace));
            dp[i][j]=ans;
        }
        
        dp[i][j]=ans;
        return dp[i][j];
        
    }
    
    
    int solve(string &w1,string &w2,int i,int j)
    {
        
        if(i==w1.length())
        {
            return w2.length()-j;
        }
        
        if(j==w2.length())
        {
            return w1.length()-i;
        }

        
        
        int ans=0;
        
        if(w1[i]==w2[j])
        {
            return solve(w1,w2,i+1,j+1);
        }
        else
        {
            
            int insert=1+solve(w1,w2,i,j+1);
            int del=1+solve(w1,w2,i+1,j);
            int replace=1+solve(w1,w2,i+1,j+1);
            
            ans=min(insert,min(del,replace));
        }
        
        return ans;
        
    }
    int minDistance(string word1, string word2) 
    {
        // return solve(word1,word2,0,0);    
        
        // vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        //  return solveM(word1,word2,0,0,dp);    
        
        // return solveT(word1,word2);
        
        if(word1.length()==0)
        {
            return word2.length();
        }
        else if(word2.length()==0)
        {
            return word1.length();
        }
         return solveS(word1,word2);
    }
};
