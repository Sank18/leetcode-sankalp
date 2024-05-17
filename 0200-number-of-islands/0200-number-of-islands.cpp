class Solution {
public:
    int delrow[4]={0,0,1,-1};
    int delcol[4]={1,-1,0,0};
    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m)
    {
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            int nrow=q.front().first;
            int ncol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=nrow+delrow[i];
                int nc=ncol+delcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]=='1')
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    count++;
                    bfs(i,j,grid,vis,n,m);
                }
            }
        }
        return count;
        
    }
};