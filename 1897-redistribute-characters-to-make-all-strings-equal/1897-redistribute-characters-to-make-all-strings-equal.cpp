class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>umap;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                umap[words[i][j]]++;
            }
        }
        int n=words.size();
        for(auto it:umap)
        {
            if(it.second%n==0)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};