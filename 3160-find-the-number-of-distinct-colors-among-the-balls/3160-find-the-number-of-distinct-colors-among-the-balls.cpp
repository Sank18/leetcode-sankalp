class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>umap;
        unordered_map<int,int>colors;
        vector<int>res;
        for(auto it:queries)
        {
            int ball=it[0];
            int color=it[1];
            if(umap.find(ball)==umap.end())
            {
                umap[ball]=color;
                colors[color]++;
            }
            if(umap.find(ball)!=umap.end())
            {
                int currcolor=umap[ball];
                colors[currcolor]--;
                if(colors[currcolor]==0)
                {
                    colors.erase(currcolor);
                }
                umap[ball]=color;
                colors[color]++;
                
            }
            res.push_back(colors.size());
            
        }
        return res;
        
    }
};