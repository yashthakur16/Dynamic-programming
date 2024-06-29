//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


bool solveS(int N,int arr[],int target)
{
    vector<int>next(target+1,0);
    vector<int>curr(target+1,0);
   curr[0]=1;
   next[0]=1;
    
    
    
    for(int index=N-1;index>=0;index--)
    {
        for(int sum=0;sum<=target/2;sum++)
        {
        bool include=0;
        if(sum-arr[index]>=0)
            include=next[sum-arr[index]];
        
        bool exclude=next[sum];
        
        curr[sum]=include or exclude;
       
        }
         next=curr;
    }
    
        return  next[target/2];
    
}

int solveT(int N,int arr[],int target)
{
    vector<vector<int>> dp( target+1 , vector<int> (N+1,0));
    for(int i=0;i<=N;i++)
    {
        dp[0][i]=1;
    }
    
    
    
    for(int sum=0;sum<=target;sum++)
    {
        for(int index=N-1;index>=0;index--)
        {
        int include=0;
        if(sum-arr[index]>=0)
        include=dp[sum-arr[index]][index+1];
        
        int exclude=dp[sum][index+1];
        
        if(include==1||exclude==1)
        {
            dp[sum][index]=1;
        }
        else
        {
             dp[sum][index]=0;
        }
        }
    }
    
        return  dp[target][0];
    
}

int solveM(int N,int arr[],int sum,int index,vector<vector<int>> &dp)
    {
        if(index>=N)
        {
            return 0;
        }
        if(sum==0)
        {
            return 1;
        }
        if(sum<0)
        {
            return 0;
        }
        
        if(dp[sum][index]!=-1)
        {
            return dp[sum][index];
        }
        
        int include=solveM(N,arr,sum-arr[index],index+1,dp);
        int exclude=solveM(N,arr,sum,index+1,dp);
        
        
        
        if(include==1||exclude==1)
        {
            dp[sum][index]=1;
            return dp[sum][index];
        }
        
        dp[sum][index]=0;
        return dp[sum][index];
    }

    int solve(int N,int arr[],int sum,int index)
    {
        if(index>=N)
        {
            return 0;
        }
        if(sum==0)
        {
            return 1;
        }
        if(sum<0)
        {
            return 0;
        }
        
        int include=solve(N,arr,sum-arr[index],index+1);
        int exclude=solve(N,arr,sum,index+1);
        
        
        
        if(include==1||exclude==1)
        {
            return 1;
        }
        return 0;
    }
    int equalPartition(int N, int arr[])
    {
       int sum=0;
       
       for(int i=0;i<N;i++ )
       {
           sum=sum+arr[i];
       }
       
       if(sum%2==1)
       {
           return 0;
       }
       
    //   sum=sum/2;
       
        //return solve(N,arr,sum,0);
       
    //   vector<vector<int>> dp( sum+1 , vector<int> (N+1,-1));
       
    //   return solveM(N,arr,sum,0,dp);
    
    // return solveT(N,arr,sum);
    
    return solveS(N,arr,sum);
       
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
