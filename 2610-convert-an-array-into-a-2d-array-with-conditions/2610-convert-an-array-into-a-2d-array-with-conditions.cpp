class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        map<int,int>umap;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
            maxi=max(maxi,umap[nums[i]]);
        }
        vector<vector<int>>ans;
        int count=1;
        while(count<=maxi)
        {
            vector<int>level;
            for(auto it:umap)
            {
                if(it.second>=count)
                {
                  level.push_back(it.first);  
                }
                
                
                
            }
            count++;
            cout<<count<<endl;
            ans.push_back(level);
        }
        return ans;
       
        
    }
};