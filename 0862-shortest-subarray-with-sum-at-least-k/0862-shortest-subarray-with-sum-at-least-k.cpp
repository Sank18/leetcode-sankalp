class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<long long int,long long int>>q;
        long long sum=0;
        long long int ans=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(sum>=k)
            {
                ans=min(ans,(long long)(i-0+1));
            }
            while(!q.empty() && sum-q.front().first>=k)
            {
                ans=min(ans,(long long)(i-(q.front().second)));
                q.pop_front();
            }
            while(!q.empty() && sum<=q.back().first)
            {
                q.pop_back();
            }
            q.push_back({sum,i});
        }
        if(ans==LLONG_MAX)
        {
            return -1;
        }
        return ans;
        
    }
};