class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>umap;
        for(int i=0;i<s.size();i++)
        {
            umap[s[i]]++;
        }
        if(s.size() <k)
        {
            return false;
        }
        int count=0;
        for(auto it:umap)
        {
            if(it.second%2!=0)
            {
                count++;
            }
        }
        if(count>k)
        {
            return false;
        }
        return true;
        
        
    }
};