
class Solution {
public:
    
   static bool comp(vector<int>&p1,vector<int>&p2){
    if(p1[0]==p2[0])
    return p1[1]>p2[1];
    return p1[0]<p2[0];
}
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),comp);
        
        int n=envelopes.size();
        vector<int> a;
        
        for(int i=0;i<n;i++)
        {
            a.push_back(envelopes[i][1]);
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
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
            
        }
        
        return ans.size();
        
    }
};
