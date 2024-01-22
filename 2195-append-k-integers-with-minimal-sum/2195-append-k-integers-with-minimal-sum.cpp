class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.insert(nums.begin(),0);
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        long long sum=0;
        while(j<nums.size() && k>0)
        {
            long long numpos=nums[j]-nums[i]-1;
            if(numpos>=1)
            {
                numpos=min(numpos,(long long)k);
                k=k-numpos;
                int start=nums[i]+1;
                int end=nums[j]-1;
                sum=sum+(numpos*(2*start+(numpos-1)*1)/2);
            }
            
            i++;
            j++;
        }
        int start=nums[nums.size()-1]+1;
        while(k>0)
        {
            long long numpos=k;
            sum=sum+(numpos*(2*start+(numpos-1)))/2;
            k=0;
        }
        return sum;
        
    }
};