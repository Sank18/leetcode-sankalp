class Solution {
public:
    int merge(vector<int>&a,int low,int mid,int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    int j=mid+1;
    for(int i = low; i<=mid; i++) {
        while(j<=high && a[i] > 2ll*a[j]) {
                j++;
        }
            cnt += (j-(mid+1));
    }
    while(left<=mid && right<=high)
    {
        if(a[left]<=a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else{
            
            
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=temp[i-low];
    }
    return cnt;
}
int ms(vector<int>&a,int low,int high)
{
    int cnt=0;
    if(low>=high)
    {
        return 0;
    }
    int mid=(low+high)/2;
    cnt+=ms(a,low,mid);
    cnt+=ms(a,mid+1,high);
    cnt+=merge(a,low,mid,high);
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return ms(nums,0,n-1);
        
    }
};