class Solution {
public:
    
    int solveT(vector<vector<int>>& books, int shelfWidth) {
       int n = books.size();
        vector<int> dp(n + 1, INT_MAX); 
        
        dp[0] = 0; 
        
        for (int i = 1; i <= n; ++i) {
            int width = 0;
            int height = 0;
            for (int j = i; j > 0; --j) {
                width += books[j - 1][0];
                if (width > shelfWidth) break;
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        
        return dp[n];
    }

    
     int solveM(vector<vector<int>>& books, int shelfWidth,int index, int original,int height,vector<vector<int>> &dp)
    {
        if(index>=books.size())
        {
            return height;
        }
         
         if(dp[index][shelfWidth]!=-1)
         {
             return dp[index][shelfWidth];
         }
        
        int sameShelf=INT_MAX;
        int newShelf=INT_MAX;
      
        
        //newShelf
        
        newShelf=height+solveM(books,original-books[index][0],index+1,original,books[index][1],dp);
        
        
        //sameShelf
        if(shelfWidth>=books[index][0])
        {
            sameShelf=solveM(books,shelfWidth-books[index][0],index+1,original,max(height,books[index][1]),dp);
        }
    
        
        
        dp[index][shelfWidth]= min(newShelf,sameShelf);
         
         return dp[index][shelfWidth];
    
        
    }
    
    int solve(vector<vector<int>>& books, int shelfWidth,int index, int original,int height)
    {
        if(index>=books.size())
        {
            return height;
        }
        
        int sameShelf=INT_MAX;
        int newShelf=INT_MAX;
      
        
        //newShelf
        
        newShelf=height+solve(books,original-books[index][0],index+1,original,books[index][1]);
        
        
        //sameShelf
        if(shelfWidth>=books[index][0])
        {
            sameShelf=solve(books,shelfWidth-books[index][0],index+1,original,max(height,books[index][1]));
        }
    
        
        
        return min(newShelf,sameShelf);
    
        
    }
    
    
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
//         int height=books[0][1];
//         // return solve(books,shelfWidth-books[0][0],1,shelfWidth,height);
        
        
//         vector<vector<int>> dp(books.size(),vector<int>(shelfWidth,-1));
//         return solveM(books,shelfWidth-books[0][0],1,shelfWidth,height,dp);
        
        return solveT(books,shelfWidth);
        
    }
};
