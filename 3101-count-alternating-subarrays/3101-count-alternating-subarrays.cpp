class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long curr=1;
        long long res=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                curr++;
                res=res+curr;
            }
            else
            {
                curr=1;
                res=res+curr;
            }
        }
        return res;
        
        
    }
};