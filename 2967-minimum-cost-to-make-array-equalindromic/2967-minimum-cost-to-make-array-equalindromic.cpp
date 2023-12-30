class Solution {
public:
    bool ispal(int num)
    {
        bool flag=true;
        string temp=to_string(num);
        int start=0;
        int end=temp.size()-1;
        while(start<=end)
        {
            if(temp[start]!=temp[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int findlarge(int number)
    {
        int ans=0;
        for(int i=number;i>=1;i--)
        {
            if(ispal(i))
            {
                return i;
            }
        }
        return 0;
    }
    int findsmall(int number)
    {
        int ans=0;
        for(int i=number;i<=1e9;i++)
        {
            if(ispal(i))
            {
                return i;
            }
        }
        return 0;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=0;
        if(n%2!=0)
        {
            mid=n/2;
        }
        if(n%2==0)
        {
            mid=(n+1)/2;
        }
        int number=nums[mid];
        //find largest pallindrome smaller than number
        int large=findlarge(number);
        //find smallest pallindrome larger than number
        int small=findsmall(number);
        
        long long int cost1=0;
        long long int cost2=0;
        for(int i=0;i<nums.size();i++)
        {
            cost1+=abs(nums[i]-large);
            cost2+=abs(nums[i]-small);
        }
        return  min(cost1,cost2);
        
        
    }
};