class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
        {
            return false;
        }
        vector<int>a(26,0);
        vector<int>b(26,0);
        unordered_map<char,int>umap;
        for(int i=0;i<word1.size();i++)
        {
            a[word1[i]-'a']++;
            b[word2[i]-'a']++;
            umap[word1[i]]++;
        }
        for(int i=0;i<word1.size();i++)
        {
            if(umap[word2[i]]==0)
            {
                return false;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
};