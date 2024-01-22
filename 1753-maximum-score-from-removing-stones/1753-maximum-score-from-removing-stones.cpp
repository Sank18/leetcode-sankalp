class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int>nums={a,b,c};
        sort(nums.begin(),nums.end());
        int sum1=nums[0]+nums[1];
        //sum of the two smallest array 
        int sum2=nums[2];
        //largest element 
        // agar largest elembt baaki dono sai zyada hai sum sai to mai baaki dono khatam kar saktak largest sai so mera ans hoga sum1;
        //agar mera sum1>sum2 sai sai to pehle largest ko khatam kardo optimally ab kesse kara hai mujhe matlab nahi but optimally pel diya
        if(sum1>=sum2)
        {
            return sum2+(sum1-sum2)/2;
            
        }
        else
        {
            return sum1;
        }
        
        
    }
};