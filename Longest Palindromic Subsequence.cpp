class Solution {
public:
    
     int solveS(string &text1,string &text2)
    {
       vector<int> curr(text2.size()+1,0);
        vector<int> next(text2.size()+1,0);
        
        for(int i=text1.size()-1;i>=0;i--)
        {
            for(int j=text2.size()-1;j>=0;j--)
            {
                
                if(text1[i]==text2[j])
                {
                    curr[j]= 1+next[j+1];
                    
                }
                else
                {
                    curr[j]= max(next[j],curr[j+1]);
                   
                }
            }
            next=curr;
        }
        
        return next[0];
    }
    
    
    int longestPalindromeSubseq(string s) 
    {
        string r=s;
        reverse(r.begin(),r.end());
        
        return solveS(s,r);
    }
};
