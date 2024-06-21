//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.

int solveOptimal(int a[],int n)
    {
        if(n==0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++)
        {
            if(a[i]>ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                //find the index of just next big element
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                
                ans[index]=a[i];
            }
        }
        
        return ans.size();
        
        
    }
    
    int solveS(int a[],int n)
    {
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int include=0;
                
                if(prev==-1||a[i]>a[prev])
                {
                    include=1+next[i+1];
                }
                
                int exclude=next[prev+1];
                
                curr[prev+1]=max(include,exclude);        
            }
            next=curr;
        }
        
        
        
        return next[0];
        
        
        
    }
    
    int solveT(int a[],int n)
    {
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int include=0;
                
                if(prev==-1||a[i]>a[prev])
                {
                    include=1+dp[i+1][i+1];
                }
                
                int exclude=dp[i+1][prev+1];
                
                dp[i][prev+1]=max(include,exclude);        
            }
        }
        
        
        
        return dp[0][0];
        
        
        
    }
    
    int solveM(int a[],int n, int i,int prev,vector<vector<int>> &dp)
    {
        if(i>=n)
        {
            return 0;
        }
        
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        
        int include=0;
        
        if(prev==-1||a[i]>a[prev])
        {
            include=1+solveM(a,n,i+1,i,dp);
        }
        
        int exclude=solveM(a,n,i+1,prev,dp);
        
        dp[i][prev+1]=max(include,exclude);
        
        return dp[i][prev+1];
        
        
        
    }
    
    int solve(int a[],int n, int i,int prev)
    {
        if(i>=n)
        {
            return 0;
        }
        
        int include=0;
        
        if(a[i]>prev)
        {
            include=1+solve(a,n,i+1,a[i]);
        }
        
        int exclude=solve(a,n,i+1,prev);
        
        return max(include,exclude);
        
        
        
    }
    int longestSubsequence(int n, int a[])
    {
        // return solve(a,n,0,-1);
        // vector<vector<int>> dp(n+1,(vector<int>(n+1,-1)));
        // return solveM(a,n,0,-1,dp);
        
        // return solveT(a,n);
        
       // return solveS(a,n);
        solveOptimal(a,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
