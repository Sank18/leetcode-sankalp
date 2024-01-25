class Solution {
public:
    int dp[2000+1][2000+1];
    int f(int ind,int t,vector<int>&s)
    {
        if(ind>=s.size())
        {
            return 0;
        }
        if(dp[ind+1000][t]!=-1)
        {
            return dp[ind+1000][t];
        }
        int include=0;
        int exclude=0;
        include=t*s[ind]+f(ind+1,t+1,s);
        exclude=f(ind+1,t,s);
        return dp[ind+1000][t]=max(include,exclude);
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        int timexp=1;
        return f(0,timexp,s);
        
    }
};