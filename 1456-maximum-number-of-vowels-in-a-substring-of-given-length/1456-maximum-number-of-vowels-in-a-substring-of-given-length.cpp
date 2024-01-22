class Solution {
public:
    int maxVowels(string s, int k) { 
        int vowels=0;
        vector<int>dp(s.size()+1,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u')
            {
                vowels++;
            }
            dp[i]=vowels;
            
        }
        int n=s.size();
        int ans=INT_MIN;
        int curr=0;
        for(int i=0;i<=(n-k);i++)
        {
            int reach=i+k-1;
            curr=dp[reach];
            if(i>0)
            {
                curr=curr-dp[i-1];
            }
            ans=max(ans,curr);
            
        }
        return ans;
        
    }
};