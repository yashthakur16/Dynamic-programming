class Solution {
public:
    
    int solveS(vector<int>& prices,int fee)
    {
         vector<int> curr(3,0);
        vector<int> next(3,0);
        
        for(int index=prices.size()-1;index>=0;index--)
        {
            for(int stock=1;stock>=0;stock--)
            {
                 int profit=0;

                if(!stock)
                {
                    int buy=profit-prices[index]+next[true];
                    int nobuy=next[false];
                    profit=max(profit,max(buy,nobuy));
                }
                else
                {
                    int sell=profit-fee+prices[index]+next[false];
                    int nosell=next[true];
                    profit=max(profit,max(sell,nosell));
                }

               curr[stock]=profit;
            }
            next=curr;
        }
        
        return next[0];
    }
    
    int solveT(vector<int>& prices,int fee)
    {
         vector<vector<int>> dp(prices.size()+1,vector<int>(3,0));
        
        for(int index=prices.size()-1;index>=0;index--)
        {
            for(int stock=1;stock>=0;stock--)
            {
                 int profit=0;

                if(!stock)
                {
                    int buy=profit-prices[index]+dp[index+1][true];
                    int nobuy=dp[index+1][false];
                    profit=max(profit,max(buy,nobuy));
                }
                else
                {
                    int sell=profit-fee+prices[index]+dp[index+1][false];
                    int nosell=dp[index+1][true];
                    profit=max(profit,max(sell,nosell));
                }

               dp[index][stock]=profit;
            }
        }
        
        return dp[0][0];
    }
    
    int solveM(vector<int>& prices, int fee,int index,bool stock,vector<vector<int>> &dp)
    {
        if(index>=prices.size())
        {
            return 0;
        }
        
        if(dp[index][stock]!=-1)
        {
            return dp[index][stock];
        }
        
        int profit=0;
        
        if(!stock)
        {
            int buy=profit-prices[index]+solveM(prices,fee,index+1,true,dp);
            int nobuy=solveM(prices,fee,index+1,false,dp);
            profit=max(profit,max(buy,nobuy));
        }
        else
        {
            int sell=profit-fee+prices[index]+solveM(prices,fee,index+1,false,dp);
            int nosell=solveM(prices,fee,index+1,true,dp);
            profit=max(profit,max(sell,nosell));
        }
        
       dp[index][stock]=profit;
        return dp[index][stock];
    }
    
    int solve(vector<int>& prices, int fee,int index,bool stock)
    {
        if(index>=prices.size())
        {
            return 0;
        }
        
        int profit=0;
        
        if(!stock)
        {
            int buy=profit-prices[index]+solve(prices,fee,index+1,true);
             int nobuy=solve(prices,fee,index+1,false);
            profit=max(profit,max(buy,nobuy));
        }
        else
        {
            int sell=profit-fee+prices[index]+solve(prices,fee,index+1,false);
            int nosell=solve(prices,fee,index+1,true);
            profit=max(profit,max(sell,nosell));
        }
        
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        // return solve(prices,fee,0,false);
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        
//         return solveM(prices,fee,0,false,dp);
        // return solveT(prices,fee);
        return solveS(prices,fee);
    }
};
