class Solution {
public:
    int power(int x,int y,int mod)
    {
        if(y==0)
        {
            return 1;
        }
        long long temp=power(x,y/2,mod)%mod;
        if(y%2==0)
        {
            return (temp*temp)%mod;
        }
        return ((((x*temp)%mod)*temp)%mod);
    }
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,vector<int>>umap;
       for(int i=0;i<nums.size();i++)
       {
           umap[nums[i]].push_back(i);
       }
        //finding possible partition places
        int groups=0;
        int nextgroup=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i>nextgroup)
            {
                groups++;
            }
            int lastoccurence=umap[nums[i]].back();
            // cout<<lastoccurence<<endl;
            nextgroup=max(nextgroup,lastoccurence);
        }
        int mod=1e9+7;
        return power(2,groups-1,mod);
        
        
        
    }
};