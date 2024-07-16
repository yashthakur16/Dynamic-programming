class Solution {
public:
    
    
    bool solveS(string &s,string &p)
    {
        vector<int> prev(p.size()+1,0);
        vector<int> curr(p.size()+1,0);
        
         prev[0]=true;
        for(int j=1;j<=p.size();j++)
        {
            bool flag=true;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    flag= false;
                    break;
                }
            }
           prev[j]=flag;
            
        }
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=p.size();j++)
            {
                 if(s[i-1]==p[j-1]||p[j-1]=='?')
                {
                    curr[j]= prev[j-1];
                }
                else if(p[j-1]=='*')
                {
                    curr[j]= (prev[j])||(curr[j-1]);
                    
                }
                else
                {
                    curr[j]=false;

                }
            }
            prev=curr;
        }
        
        return prev[p.size()];
    }
    
    bool solveT(string &s,string &p)
    {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
        
        dp[0][0]=true;
        for(int j=1;j<=p.size();j++)
        {
            bool flag=true;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    flag= false;
                    break;
                }
            }
            dp[0][j]=flag;
            
        }
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=p.size();j++)
            {
                 if(s[i-1]==p[j-1]||p[j-1]=='?')
                {
                    dp[i][j]= dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]= (dp[i-1][j])||(dp[i][j-1]);
                    
                }
                else
                {
                    dp[i][j]=false;

                }
            }
        }
        
        return dp[s.size()][p.size()];
        
        
    }
    
     bool solveM(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i==0&&j==0)
        {
            return true;
        }
        
        if(i>0&&j==0)
        {
            return false;
        }
        
        if(i==0&&j>0)
        {
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    return false;
                }
            }
            return true;
        }
         
         if(dp[i][j]!=-1)
         {
             return dp[i][j];
         }
        
       
        
        if(s[i-1]==p[j-1]||p[j-1]=='?')
        {
            dp[i][j]= solveM(s,p,i-1,j-1,dp);
            return dp[i][j];
        }
        else if(p[j-1]=='*')
        {
            dp[i][j]= solveM(s,p,i-1,j,dp)||solveM(s,p,i,j-1,dp);
            return dp[i][j];
        }
        else
        {
            return  false;
            
        }
        
        return false;
    }
    
    
    bool solve(string &s,string &p,int i,int j)
    {
        if(i<0&&j<0)
        {
            return true;
        }
        
        if(i>=0&&j<0)
        {
            return false;
        }
        
        if(i<0&&j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        
       
        
        if(s[i]==p[j]||p[j]=='?')
        {
            return solve(s,p,i-1,j-1);
        }
        else if(p[j]=='*')
        {
            return solve(s,p,i-1,j)||solve(s,p,i,j-1);
        }
        else
        {
            return false;
        }
        
        return false;
    }
    bool isMatch(string s, string p) 
    {
        int i=s.size();
        int j=p.size();
        
        // return solve(s,p,i,j);
        
        // vector<vector<int>> dp(i+1,vector<int>(j+1,-1));
        // return solveM(s,p,i,j,dp);
        
        return solveS(s,p);
    }
};
