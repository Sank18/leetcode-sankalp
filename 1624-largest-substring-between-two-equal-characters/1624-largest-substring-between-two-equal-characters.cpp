class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>umap;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(umap.find(s[i])!=umap.end())
            {
                ans=max(ans,(i-umap[s[i]]));
            }
            else
            {
                umap[s[i]]=i;
            }
        }
        return ans-1;
    
        
    }
};