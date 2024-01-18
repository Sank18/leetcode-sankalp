class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int gcdi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            gcdi=gcd(gcdi,nums[i]);
        }
        if(gcdi==1)
        {
            return true;
        }
        return false;
        
    }
};