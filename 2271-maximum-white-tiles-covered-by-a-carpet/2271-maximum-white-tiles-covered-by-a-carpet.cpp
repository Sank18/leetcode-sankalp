class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int tile=0;
        sort(tiles.begin(),tiles.end());
        vector<int>prefix;
        for(auto it:tiles)
        {
            int start=it[0];
            int end=it[1];
            tile=tile+end-start+1;
            prefix.push_back(tile);
        }
        int ans=INT_MIN;
        for(int i=0;i<tiles.size();i++)
        {
            //carpet placed at current time start
            
            int reach=tiles[i][0]+carpetLen-1;
            
            
            
                //calculate till which index i can go 
                int start=i;
                int end=tiles.size()-1;
                int index=i;
                while(start<=end)
                {
                    int mid=(start+end)/2;
                    if(tiles[mid][0]<=reach)
                    {
                        start=mid+1;
                        index=mid;
                    }
                    else
                    {
                        end=mid-1;
                    }
                }
                //index stores the index of the interval till which my carpet can reach if kept at i
                int sum=prefix[index];
                if(i>0)
                {
                    sum=sum-prefix[i-1];
                }
                if(tiles[index][1]>reach)
                {
                    sum=sum-(tiles[index][1]-reach);
                }
                ans=max(ans,sum);
                
            
           
            
        }
         return ans;
        
        
    }
};