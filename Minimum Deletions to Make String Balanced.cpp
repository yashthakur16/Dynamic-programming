class Solution {
public:
    
      int solveT(string s)
    {
          int n=s.size();
          
        vector<vector<int>> dp(s.size()+1,vector<int>(4,INT_MAX));
          
          dp[n][0]=dp[n][1]=dp[n][2]=0;
      
          
        for(int index=s.size()-1;index>=0;index--)
        {
            for(int prevIdx=2;prevIdx>=0;prevIdx--)
            {
                    
     
                char prev = (prevIdx == 0 ? 'a' : (prevIdx == 1 ? 'b' : '-1'));
               
        int del=INT_MAX;
        int nodel=INT_MAX;
        
        
        //delete
        if(s[index]!=prev)
        {
            del=1+dp[index+1][prevIdx];
        }
        
        //noDelete
        if(prev!='b'||s[index]=='b')
        {   
            int newPrevIdx = (s[index] == 'a' ? 0 : (s[index] == 'b' ? 1 : 2));
                    nodel = dp[index + 1][newPrevIdx];
        }
        
        
        dp[index][prevIdx]=min(del,nodel);
            }
        }
          
          
        
        return dp[0][2];
        
        
    }
    
    
    
    int solveM(string s,int index,char prev,vector<vector<int>> &dp)
    {
        int prevIdx = (prev == 'a' ? 0 : (prev == 'b' ? 1 : 2));
        
        if(index>=s.size())
        {
            return 0;
        }
        
        if(dp[index][prevIdx]!=-1)
        {
            return dp[index][prevIdx];
        }
        
        
        int del=INT_MAX;
        int nodel=INT_MAX;
        
        
        //delete
        if(s[index]!=prev)
        {
            del=1+solveM(s,index+1,prev,dp);
        }
        
        //noDelete
        if(prev!='b'||s[index]=='b')
        {
            prev=s[index];
            nodel=solveM(s,index+1,prev,dp);
        }
        
        
        dp[index][prevIdx]=min(del,nodel);
        
        return dp[index][prevIdx];
        
        
    }
    
    int solve(string s,int index,char prev)
    {
        if(index>=s.size())
        {
            return 0;
        }
        
        
        int del=INT_MAX;
        int nodel=INT_MAX;
        
        
        //delete
        if(s[index]!=prev)
        {
            del=1+solve(s,index+1,prev);
        }
        
        //noDelete
        if(prev!='b'||s[index]=='b')
        {
            prev=s[index];
            nodel=solve(s,index+1,prev);
        }
        
        
        return min(del,nodel);
        
        
    }
    
    
    int minimumDeletions(string s) 
    {
        // char prev='-1';
        // return solve(s,0,prev);
        
        // vector<vector<int>> dp(s.size(),vector<int>(3,-1));
        
        
        // return solveM(s,0,prev,dp);
        
        return solveT(s);
        
    }
};
