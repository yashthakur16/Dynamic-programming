class Solution {
public:
    
    int solveS(vector<int>& prices)
    {
        int n=prices.size();
        vector<int> next(2,0);
        vector<int> curr(2,0);
        
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int profit=0;
        
                if(buy==0)
                {
                    int buy=profit-prices[index]+next[1];
                    int nobuy=next[0];
                    profit=max(profit,max(buy,nobuy));

                }
                else
                {
                    int sell=profit+prices[index]+next[0];
                    int nosell=next[1];
                    profit=max(profit,max(sell,nosell));

                }

                curr[buy]=profit;
            }
            next=curr;
        }
        return next[0];
    }
    
    int solveT(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(3,0));
        
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int profit=0;
        
                if(buy==0)
                {
                    int buy=profit-prices[index]+dp[index+1][1];
                    int nobuy=dp[index+1][0];
                    profit=max(profit,max(buy,nobuy));

                }
                else
                {
                    int sell=profit+prices[index]+dp[index+1][0];
                    int nosell=dp[index+1][1];
                    profit=max(profit,max(sell,nosell));

                }

                dp[index][buy]=profit;
            }
        }
        return dp[0][0];
    }
    
    int solveM(vector<int>& prices,int n,int index,bool buy,vector<vector<int>> &dp)
    {
        if(index>=n)
        {
            return 0;
        }
        
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        int profit=0;
        
        if(buy==false)
        {
            int buy=profit-prices[index]+solveM(prices,n,index+1,true,dp);
            int nobuy=solveM(prices,n,index+1,false,dp);
            profit=max(profit,max(buy,nobuy));
            
        }
        else
        {
            int sell=profit+prices[index]+solveM(prices,n,index+1,false,dp);
            int nosell=solveM(prices,n,index+1,true,dp);
            profit=max(profit,max(sell,nosell));
            
        }
        
        dp[index][buy]=profit;
        return dp[index][buy];
    }
    int solve(vector<int>& prices,int n,int index,bool buy)
    {
        if(index>=n)
        {
            return 0;
        }
        
        int profit=0;
        
        if(buy==false)
        {
            int buy=profit-prices[index]+solve(prices,n,index+1,true);
            int nobuy=+solve(prices,n,index+1,false);
            profit=max(profit,max(buy,nobuy));
            
        }
        else
        {
            int sell=profit+prices[index]+solve(prices,n,index+1,false);
            int nosell=solve(prices,n,index+1,true);
            profit=max(profit,max(sell,nosell));
            
        }
        
        
        return profit;
    }
    
    

    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        bool buy=false;
        // return solve(prices,n,0,buy);
        
//         vector<vector<int>> dp(n,vector<int>(2,-1));
        
//         return solveM(prices,n,0,buy,dp);
        
        // return solveT(prices);
         return solveS(prices);
        
    }
};
