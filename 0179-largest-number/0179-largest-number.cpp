class Solution {
public:
    static bool cmp(string a,string b)
    {
       return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string>num;
        for(int i=0;i<nums.size();i++)
        {
            num.push_back(to_string(nums[i]));
        }
        
        sort(num.begin(),num.end(),cmp);
        if(num[0]=="0")
        {
            return "0";
        }
        for(int i=0;i<num.size();i++)
        {
            // cout<<num[i]<<endl;
            ans+=num[i];
        }
        return ans;
        
        
    }
};