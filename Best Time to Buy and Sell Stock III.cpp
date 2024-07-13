class Solution {
public:
    
     int solveS(vector<int>& prices,int n)
    {
        
         vector<vector<int>> curr(2,vector<int>(4,0));
         vector<vector<int>> next(2,vector<int>(4,0));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int stock=1;stock>=0;stock--)
            {
                for(int k=2;k>=0;k--)
                {
                   int profit=0;

                    if(stock==false)
                    {
                        int buy=profit-prices[index]+next[true][k];
                        int nobuy=next[false][k];
                        profit=max(profit,max(buy,nobuy));
                    }
                    else
                    {
                        int sell=profit+prices[index]+next[false][k+1];
                        int nosell=next[true][k];
                        profit=max(profit,max(sell,nosell));
                    }

                    curr[stock][k]=profit; 
                }
            }
            next=curr;
        }
        return next[0][1];
    }
    
    
    int solveT(vector<int>& prices,int n)
    {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(4,0)));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int stock=1;stock>=0;stock--)
            {
                for(int k=2;k>=0;k--)
                {
                   int profit=0;

                    if(stock==false)
                    {
                        int buy=profit-prices[index]+dp[index+1][true][k];
                        int nobuy=dp[index+1][false][k];
                        profit=max(profit,max(buy,nobuy));
                    }
                    else
                    {
                        int sell=profit+prices[index]+dp[index+1][false][k+1];
                        int nosell=dp[index+1][true][k];
                        profit=max(profit,max(sell,nosell));
                    }

                    dp[index][stock][k]=profit; 
                }
            }
        }
        return dp[0][0][1];
    }
    
    
    int solveM(vector<int>& prices, int n, int index,int k, bool stock,vector<vector<vector<int>>> &dp)
    {
        if(index>=n || k>=2)
        {
            return 0;
        }
        
        if(dp[index][stock][k]!=-1)
        {
            return dp[index][stock][k];
        }
        
        int profit=0;
        
        if(stock==false)
        {
            int buy=profit-prices[index]+solveM(prices,n,index+1,k,true,dp);
            int nobuy=solveM(prices,n,index+1,k,false,dp);
            profit=max(profit,max(buy,nobuy));
        }
        else
        {
            int sell=profit+prices[index]+solveM(prices,n,index+1,k+1,false,dp);
            int nosell=solveM(prices,n,index+1,k,true,dp);
            profit=max(profit,max(sell,nosell));
        }
        
        dp[index][stock][k]=profit;
        return dp[index][stock][k];
    }
    
    int solve(vector<int>& prices, int n, int index,int k, bool stock)
    {
        if(index>=n || k>=2)
        {
            return 0;
        }
        
        int profit=0;
        
        if(stock==false)
        {
            int buy=profit-prices[index]+solve(prices,n,index+1,k,true);
            int nobuy=solve(prices,n,index+1,k,false);
            profit=max(profit,max(buy,nobuy));
        }
        else
        {
            int sell=profit+prices[index]+solve(prices,n,index+1,k+1,false);
            int nosell=solve(prices,n,index+1,k,true);
            profit=max(profit,max(sell,nosell));
        }
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        // return solve(prices,n,0,0,false);
        
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solveM(prices,n,0,0,false,dp);
        
       // return solveT(prices,n);
        return solveS(prices,n);
        
    }
};
