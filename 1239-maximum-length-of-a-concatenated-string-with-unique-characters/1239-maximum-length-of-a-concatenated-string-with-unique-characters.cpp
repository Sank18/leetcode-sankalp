class Solution {
public:
    unordered_map<string,int>umap;
    bool check(string &s1,string &s2)
    {
        vector<int>hash(26,0);
        for(int i=0;i<s1.size();i++)
        {
            if(hash[s1[i]-'a']>0)
            {
                return true;
            }
            hash[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++)
        {
            if(hash[s2[i]-'a']>0)
            {
                return true;
            }
            hash[s2[i]-'a']++;
        }
        return false;
    }
    int f(int ind,string temp,vector<string>&arr)
    {
        if(ind>=arr.size())
        {
            return temp.size();
        }
        if(umap.find(temp)!=umap.end())
        {
            return umap[temp];
        }
        int include=0;
        int exclude=0;
        if(check(arr[ind],temp))
        {
            exclude=f(ind+1,temp,arr);
        }
        else
        {
            exclude=f(ind+1,temp,arr);
            include=f(ind+1,temp+arr[ind],arr);
        }
        umap[temp]=max(exclude,include);
        return umap[temp];
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        return f(0,temp,arr);
        
    }
};