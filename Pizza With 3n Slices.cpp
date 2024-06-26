class Solution {
public:
    
    
    int solveS(vector<int>& slices)
    {
        int k=slices.size();
        vector<int> prev(k+2,0);
        vector<int> curr(k+2,0);
        vector<int> next(k+2,0);
        
        
        for(int index=k-2;index>=0;index--)
        {
            for(int n=1;n<=k/3;n++)
            {
                 
                int take=slices[index]+next[n-1];
                int notake=curr[n];

                prev[n]= max(take,notake);
            }
           next=curr;
            curr=prev;
        }
        
        
         vector<int> prev1(k+2,0);
        vector<int> curr1(k+2,0);
        vector<int> next1(k+2,0);
        
        
        for(int index=k-1;index>=1;index--)
        {
            for(int n=1;n<=k/3;n++)
            {
                 
                int take=slices[index]+next1[n-1];
                int notake=curr1[n];

                prev1[n]= max(take,notake);
            }
            
            next1=curr1;
            curr1=prev1;
        }
        
        
        int case1=curr[k/3];
        int case2=curr1[k/3];
        
        return max(case1,case2);
    }
    
    int solveT(vector<int>& slices)
    {
        int k=slices.size();
        vector<vector<int>> dp1(k+2,vector<int>(k+2,0));
        vector<vector<int>> dp2(k+2,vector<int>(k+2,0));
        
        
        for(int index=k-2;index>=0;index--)
        {
            for(int n=1;n<=k/3;n++)
            {
                 
                int take=slices[index]+dp1[index+2][n-1];
                int notake=dp1[index+1][n];

                dp1[index][n]= max(take,notake);
            }
        }
        
        
        for(int index=k-1;index>=1;index--)
        {
            for(int n=1;n<=k/3;n++)
            {
                 
                int take=slices[index]+dp2[index+2][n-1];
                int notake=dp2[index+1][n];

                dp2[index][n]= max(take,notake);
            }
        }
        
        int case1=dp1[0][k/3];
        int case2=dp2[1][k/3];
        
        return max(case1,case2);
    }
    
    int solveM(int index,int endIndex, vector<int>& slices,int n,vector<vector<int>>&dp)
    {
        if(n==0 || index>endIndex)
        {
            return 0;
        }
        
        if(dp[index][n]!=-1)
        {
            return dp[index][n];
        }
        
        int take=slices[index]+solveM(index+2,endIndex,slices,n-1,dp);
        int notake=solveM(index+1,endIndex,slices,n,dp);
            
        dp[index][n]= max(take,notake);
        
        return dp[index][n];
    }
    
    
    int solve(int index,int endIndex, vector<int>& slices,int n)
    {
        if(n==0 || index>endIndex)
        {
            return 0;
        }
        
        int take=slices[index]+solve(index+2,endIndex,slices,n-1);
        int notake=solve(index+1,endIndex,slices,n);
            
            return max(take,notake);
    }
    int maxSizeSlices(vector<int>& slices) 
    {
        // int k=slices.size();
        
        // int case1=solve(0,k-2,slices,k/3);
        // int case2=solve(1,k-1,slices,k/3);
        
//         vector<vector<int>> dp(k,vector<int>(k,-1));
        
//          int case1=solveM(0,k-2,slices,k/3,dp);
//         vector<vector<int>> dp1(k,vector<int>(k,-1));
//         int case2=solveM(1,k-1,slices,k/3,dp1);
//         return max(case1,case2);
         
        // return solveT(slices);
        
          return solveS(slices);
        
    }
};
