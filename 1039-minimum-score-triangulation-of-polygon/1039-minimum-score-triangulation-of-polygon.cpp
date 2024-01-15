class Solution {
public:
    int dp[50][50];
    int f(int i,int j,vector<int>&values)
    {
        if(j-i<=1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            ans=min(ans,f(i,k,values)+f(k,j,values)+values[i]*values[k]*values[j]);
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,values);
        
    }
};