class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        vector<bool>sieve(101,true);
        sieve[0]=false;
        sieve[1]=false;
        for(int i=2;i<=100;i++)
        {
            if(sieve[i]==true)
            {
                for(int j=i*i;j<=100;j=j+i)
                {
                    sieve[j]=false;
                }
            }
        }
        bool flag1=false;
        bool flag2=false;
        int val=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(sieve[nums[i]]==true)
            {
                val=i;
                flag1=true;
                break;
            }
            
        }
        int val2=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(sieve[nums[i]]==true)
            {
                val2=i;
                flag2=true;
                break;
            }
        }
        if(flag1==false || flag2==false)
        {
            return 0;
        }
        cout<<val2<<" "<<val<<endl;
        return abs(val2-val);
        
    }
};