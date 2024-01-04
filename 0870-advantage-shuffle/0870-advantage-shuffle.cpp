class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int,int>umap;
        for(auto it:nums1)
        {
            umap[it]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            auto it=umap.upper_bound(nums2[i]);
            if(it==umap.end())
            {
                auto itr=umap.begin();
                ans.push_back((*itr).first);
                umap[(*itr).first]--;
                if(umap[(*itr).first]==0)
                {
                    umap.erase((*itr).first);
                }
            }
            else
            {
                ans.push_back((*it).first);
                umap[(*it).first]--;
                if(umap[(*it).first]==0)
                {
                    umap.erase((*it).first);
                }
            }
            
        }
        return ans;
        
    }
};