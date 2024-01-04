class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
        }
        int op=0;
        for(auto it:umap)
        {
            if(it.second%3==0)
            {
                op+=it.second/3;
            }
            else
            {
                if(it.second==1)
                {
                    return -1;
                }
                int temp=it.second;
                while(temp%3!=0 )
                {
                    temp=temp-2;
                    op++;
                    
                }
                op+=temp/3;
                
            }
        }
        return op;
        
    }
};