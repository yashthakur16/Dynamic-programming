class Solution {
public:
    
    int solveS(vector<int>& satisfaction)
    {
         
         int n=satisfaction.size();
         
         
         vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
         
     
         
        for(int index=n-1 ;index>=0;index--)
        {
            for(int time=index;time>=0;time--)
                {
                    int include=satisfaction[index]*(time+1)+next[time+1];

                    int exclude=next[time];

                    curr[time]= max(include,exclude);
                }
            next=curr;
        }
       
        
        return next[0];
    }
    
    
     int solveT(vector<int>& satisfaction)
    {
         
         int n=satisfaction.size();
         
         
         vector<vector<int>> dp(n+1,(vector(n+1,0)));
         
     
         
        for(int index=n-1 ;index>=0;index--)
        {
            for(int time=index;time>=0;time--)
                {
                    int include=satisfaction[index]*(time+1)+dp[index+1][time+1];

                    int exclude=dp[index+1][time];

                    dp[index][time]= max(include,exclude);
                }
        }
       
        
        return dp[0][0];
    }
    
    int solveM(vector<int>& satisfaction,int index,int time,vector<vector<int>> &dp)
    {
        if(index>=satisfaction.size())
        {
            return 0;
        }
        
        if(dp[index][time]!=INT_MIN)
        {
            return dp[index][time];
        }
       
        int include=satisfaction[index]*(time+1)+solveM(satisfaction,index+1,time+1,dp);
        
        int exclude=solveM(satisfaction,index+1,time,dp);
        
        dp[index][time]= max(include,exclude);
        return dp[index][time];
    }
    
    int solve(vector<int>& satisfaction,int index,int time)
    {
        if(index>=satisfaction.size())
        {
            return 0;
        }
       
        int include=satisfaction[index]*(time+1)+solve(satisfaction,index+1,time+1);
        
        int exclude=solve(satisfaction,index+1,time);
        
        return max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) 
    {
         sort(satisfaction.begin(),satisfaction.end());
        
        return solveS(satisfaction);
        // return solveT(satisfaction);
//         int n=satisfaction.size();
       
//         vector<vector<int>> dp(n,(vector(n,INT_MIN)));
        
        
        // return solveM(satisfaction,0,0,dp);
        
        // return solve(satisfaction,0,0);
        
        
    }
};
