class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>umap;
        for(auto it:matches)
        {
            umap[it[0]]=0;
            umap[it[1]]=0;
        }
        for(auto it:matches)
        {
            umap[it[1]]++;
        }
        vector<int>winners;
        vector<int>oneloss;
        for(auto it:umap)
        {
            if(it.second==0)
            {
                winners.push_back(it.first);
            }
            if(it.second==1)
            {
                oneloss.push_back(it.first);
            }
        }
        vector<vector<int>>ans;
        sort(winners.begin(),winners.end());
        sort(oneloss.begin(),oneloss.end());
        ans.push_back(winners);
        ans.push_back(oneloss);
        return ans;
        
        
    }
};