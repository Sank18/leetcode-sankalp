class Solution {
public:
    bool ispos(vector<int>&piles,int speed,int h)
    {
        long long hours=0;
        for(int i=0;i<piles.size();i++)
        {
             hours+=(long long)ceil((double)(piles[i])/speed);
        }
        if(hours>h)
        {
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=1e9;
        int ans=INT_MAX;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(ispos(piles,mid,h))
            {
                ans=min(ans,mid);
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
        
    }
};