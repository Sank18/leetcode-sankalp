class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1;
        long long sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            sum+=(long long)nums[i];
            if(i<n && i>=1 && sum>nums[i+1])
            {
                ans=max(ans,sum+nums[i+1]);
            }
        }
        return ans;
    }
};