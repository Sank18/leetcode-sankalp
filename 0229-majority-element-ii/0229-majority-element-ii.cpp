class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1;
        int num2=-1;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==num1)
            {
                count1++;
            }
            else if(nums[i]==num2)
            {
                count2++;
            }
            else if(count1==0)
            {
                count1=1;
                num1=nums[i];
            }
            else if(count2==0)
            {
                count2=1;
                num2=nums[i];
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==num1)
            {
                c1++;
            }
            else if(nums[i]==num2)
            {
                c2++;
            }
        }
        vector<int>ans;
        int n=nums.size();
        if(c1>n/3){
            ans.push_back(num1);
        }
        if(c2>n/3)
        {
            ans.push_back(num2);
        }
        return ans;
        
    }
};