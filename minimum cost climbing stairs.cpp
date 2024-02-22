class Solution {
public:

    int solve(vector<int>& cost,int n)
    {
        int prev2=cost[0];
        int prev1=cost[1];
        int current;
        
        for(int i=2;i<n;i++)
        {
            current= min(prev1,prev2)+cost[i];
            prev2=prev1;
            prev1=current;
        }

        

        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        
        return solve(cost,n);
    }
};
