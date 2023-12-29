class Solution {
public:
    int dp[301][11];
    int f(int ind,vector<int>&j,int d)
    {
       if(d==1)
       {
           int maxi=j[ind];
           for(int i=ind;i<j.size();i++)
           {
               maxi=max(maxi,j[i]);
           }
           return maxi;
       }
        if(dp[ind][d]!=-1)
        {
            return dp[ind][d];
        }
        int ans=INT_MAX;
        int maxi=INT_MIN;
        for(int i=ind;i<=(j.size()-d);i++)
        {
            maxi=max(maxi,j[i]);
            ans=min(ans,maxi+f(i+1,j,d-1));
            
        }
        return dp[ind][d]=ans;
        
        
    }
    int minDifficulty(vector<int>& j, int d) {
        int n=j.size();
        if(n<d)
        {
            return -1;
        }
        
        memset(dp,-1,sizeof(dp));
        return f(0,j,d);
        
    }
};