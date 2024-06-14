//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(vector<vector<int>> mat,int i, int j,int &maxi)
    {
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }
        
        
        int right=solve(mat,i+1,j,maxi);
        int left=solve(mat,i,j+1,maxi);
        int diagonal=solve(mat,i+1,j+1,maxi);
        
        if(mat[i][j]==1)
        {
            maxi=1+min(right,min(left,diagonal));
        }
        else
        {
            return 0;
        }
        
        return maxi;
    }
    
    int solveM(vector<vector<int>> mat,int i, int j,vector<vector<int>> &dp,int &maxi)
    {
        if(i>=mat.size() || j>=mat[0].size())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int right=solveM(mat,i+1,j,dp,maxi);
        int left=solveM(mat,i,j+1,dp,maxi);
        int diagonal=solveM(mat,i+1,j+1,dp,maxi);
        
        if(mat[i][j]==1)
        {
            dp[i][j]=1+min(right,min(left,diagonal));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j]=0;
        }
        
    }
    
    
    int solveT(vector<vector<int>> mat,int n, int m,int &maxi)
    {
        
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                 
                int right=dp[i+1][j];
                int left=dp[i][j+1];
                int diagonal=dp[i+1][j+1];
                
                if(mat[i][j]==1)
                {
                    dp[i][j]=1+min(right,min(left,diagonal));
                    maxi=max(maxi,dp[i][j]);
                }
                else
                {
                    dp[i][j]= 0;
                }
            }
        }
        
       
        
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        
        
        int maxi=0;
        solveT(mat,n,m,maxi);
        return maxi;
        // int maxi=0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // solveM(mat,n,m,dp,maxi);
        
        // return maxi;
    //   
    //   solve(mat,0,0,maxi);
      
    //   return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
