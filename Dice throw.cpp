//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long solveS(int N,int faces, int X)
  {
      
      vector<long long>curr(X+1,0);
      vector<long long>prev(X+1,0);
      
     
      prev[0]=1;
      for(int dice=1;dice<=N;dice++)
      {
          for(int target=1;target<=X;target++)
          {
            long long ans=0;
            
            for(int i=1;i<=faces;i++)
            {
                if(target-i>=0)
                    ans=ans+prev[target-i];
            
            }
            
            curr[target]=ans;  
          }
          prev=curr;
      }
      
       return prev[X];
      
      
  }
  
  long long solveT(int N,int faces, int X)
  {
      vector<vector<long long>> dp(N+1,vector<long long>(X+1,0));
      
      dp[0][0]=1;
      
      for(int dice=1;dice<=N;dice++)
      {
          for(int target=1;target<=X;target++)
          {
            long long ans=0;
            
            for(int i=1;i<=faces;i++)
            {
                if(target-i>=0)
                    ans=ans+dp[dice-1][target-i];
            
            }
            
            dp[dice][target]=ans;  
          }
      }
      
       return dp[N][X];
      
      
  }
  
  long long solveM(int dice,int faces, int target,vector<vector<long long>> &dp)
    {
        if(target<0)
        {
            return 0;
        }
        if(dice==0&&target!=0)
        {
            return 0;
        }
        if(target==0&&dice==0)
        {
            return 1;
        }
        if(dice!=0&&target==0)
        {
            return 0;
        }
        if(dp[dice][target]!=-1)
        {
            return dp[dice][target];
        }
        
        long long ans=0;
        
        for(int i=1;i<=faces;i++)
        {
            ans=ans+solveM(dice-1,faces,target-i,dp);
            
        }
        
       dp[dice][target]=ans;
        
        return dp[dice][target];
    }
  
    long long solve(int dice,int faces, int target)
    {
        if(target<0)
        {
            return 0;
        }
        if(dice==0&&target!=0)
        {
            return 0;
        }
        if(target==0&&dice==0)
        {
            return 1;
        }
        if(dice!=0&&target==0)
        {
            return 0;
        }
        
        long long ans=0;
        
        for(int i=1;i<=faces;i++)
        {
            ans=ans+solve(dice-1,faces,target-i);
        }
        
        return ans;
    }
    long long noOfWays(int M , int N , int X) 
    {
        // return solve(N,M,X);
        
        // vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        // return solveM(N,M,X,dp);
        
        // return solveT(N,M,X);
        return solveS(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
