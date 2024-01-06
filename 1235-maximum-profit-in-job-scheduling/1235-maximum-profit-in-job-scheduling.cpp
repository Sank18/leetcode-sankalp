class Solution {
public:
    int dp[5*10000 + 8];
    int f(int ind,vector<vector<int>>&intervals)
    {
        if(ind>=intervals.size())
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int take=0;
        int notake=0;
        notake=f(ind+1,intervals);
        int start=ind+1;
        int end=intervals.size()-1;
        int index=intervals.size();
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(intervals[mid][0]>=intervals[ind][1])
            {
                index=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        take=intervals[ind][2]+f(index,intervals);
        return dp[ind]=max(take,notake);
        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>intervals;
        for(int i=0;i<endTime.size();i++)
        {
            intervals.push_back({startTime[i],endTime[i],profit[i]});
        }
        memset(dp,-1,sizeof(dp));
        sort(intervals.begin(),intervals.end());
        return f(0,intervals);
        
    }
};