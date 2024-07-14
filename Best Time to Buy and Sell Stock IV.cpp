class Solution {
public:
    
    int solveS(vector<int>& prices,int n,int ki)
    {
        
         vector<vector<int>> curr(2,vector<int>(ki+2,0));
         vector<vector<int>> next(2,vector<int>(ki+2,0));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int stock=1;stock>=0;stock--)
            {
                for(int k=ki;k>=0;k--)
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
    
    
    int solveT(vector<int>& prices,int n,int ki)
    {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(ki+2,0)));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int stock=1;stock>=0;stock--)
            {
                for(int k=ki;k>=0;k--)
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
    
    
    int solveM(vector<int>& prices, int n, int index,int k, bool stock,vector<vector<vector<int>>> &dp,int ki)
    {
        if(index>=n || k>=ki)
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
            int buy=profit-prices[index]+solveM(prices,n,index+1,k,true,dp,ki);
            int nobuy=solveM(prices,n,index+1,k,false,dp,ki);
            profit=max(profit,max(buy,nobuy));
        }
        else
        {
            int sell=profit+prices[index]+solveM(prices,n,index+1,k+1,false,dp,ki);
            int nosell=solveM(prices,n,index+1,k,true,dp,ki);
            profit=max(profit,max(sell,nosell));
        }
        
        dp[index][stock][k]=profit;
        return dp[index][stock][k];
    }
    
    int solve(vector<int>& prices, int n, int index,int k, bool stock,int ki)
    {
        if(index>=n || k>=ki)
        {
            return 0;
        }
        
        int profit=0;
        
        if(stock==false)
        {
            int buy=profit-prices[index]+solve(prices,n,index+1,k,true,ki);
            int nobuy=solve(prices,n,index+1,k,false,ki);
            profit=max(profit,max(buy,nobuy));
        }
        else
        {
            int sell=profit+prices[index]+solve(prices,n,index+1,k+1,false,ki);
            int nosell=solve(prices,n,index+1,k,true,ki);
            profit=max(profit,max(sell,nosell));
        }
        
        return profit;
    }
    
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        // return solve(prices,n,0,0,false,k);
        
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        // return solveM(prices,n,0,0,false,dp,k);
        
       // return solveT(prices,n,k);
       return solveS(prices,n,k);
            
    }
};
