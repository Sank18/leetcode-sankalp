class Solution {
public:
    int dp[100006][200];
    int f(int ind,string &s,int k,int prev)
    {
        if(ind>=s.size())
        {
            return 0;
        }
        if(dp[ind][prev]!=-1)
        {
            return dp[ind][prev];
        }
        int pick=0;
        int notpick=0;
        if(prev==0 || abs(s[ind]-prev)<=k)
        {
            
            pick=1+f(ind+1,s,k,s[ind]);
        }
        notpick=f(ind+1,s,k,prev);
        return dp[ind][prev]=max(pick,notpick);
    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int prev=0;
        return f(0,s,k,0);
        
        
    }
};