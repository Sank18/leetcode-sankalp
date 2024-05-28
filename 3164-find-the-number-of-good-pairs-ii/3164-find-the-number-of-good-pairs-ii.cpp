class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long,long long>umap;
        for(int i=0;i<nums2.size();i++)
        {
            umap[nums2[i]*k]++;
        }
        long long ans=0;
        for(auto el:nums1)
        {
            if(el%k!=0)
            {
                continue;
            }
            for(int i=1;i*i<=el;i++)
            {
                if(el%i!=0)
                {
                    continue;
                }
                int f2=el/i;
                ans+=umap[i];
                if(i!=f2)
                {
                    ans+=umap[f2];
                }
            }
        }
        return ans;
        
    }
};