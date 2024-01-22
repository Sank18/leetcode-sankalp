class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xored=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            xored=xored^i;
        }
        unordered_map<int,int>umap;
        int rep=0;
        for(auto it:nums)
        {
            if(umap.find(it)!=umap.end())
            {
                rep=it;
                break;
            }
            umap[it]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            xored=xored^nums[i];
        }
        return {rep,xored^rep};
        
    }
};