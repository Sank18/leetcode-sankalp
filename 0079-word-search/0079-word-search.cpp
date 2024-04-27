class Solution {
public:
    vector<int>delrow={0,1,0,-1};
    vector<int>delcol={1,0,-1,0};
    bool ans=false;
    void f(int row,int col,vector<vector<char>>&board,string &word,int k,int n,int m)
    {
        if(k==word.size())
        {
            ans=true;
            return;
        }
        if(row>=n || row<0 || col>=m ||col<0 || board[row][col]!=word[k]  )
        {
            return;
        }
        char temp=board[row][col];
        board[row][col]='1';
        
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            f(nrow,ncol,board,word,k+1,n,m);
                
            
        }
        board[row][col]=temp;
        
        
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                f(i,j,board,word,0,n,m);
                if(ans==true)
                {
                    return ans;
                }
            }
        }
        
        return ans;
        
        
    }
};