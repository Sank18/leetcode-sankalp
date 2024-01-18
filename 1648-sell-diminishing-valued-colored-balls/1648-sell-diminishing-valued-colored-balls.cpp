class Solution {
public:
    int mod=1e9+7;
    bool ispos(long long int possible,vector<int>&inventory,int orders)
    {
        long long currsold=0;
        //represents ki iss value sai upar kitni balls available hai
        
        for(int i=0;i<inventory.size();i++)
        {
            if(inventory[i]-possible>=0)
            {
                currsold+=inventory[i]-possible+1;
            }
        }
        if(currsold>=orders)
        {
            return true;
        }
        // cout<<"balls available"<<currsold<<endl;
        return false;
    }
    
        
        
        
    
    int maxProfit(vector<int>& inventory, int orders) {
        int start=0;
        int end=1e9;
        long long ans=0;
        
        sort(inventory.rbegin(),inventory.rend());
        // cout<<inventory[0]<<endl;
        
        //mid represents ki is value sai upar saari values bhech di
        //wo values agar orders sai upar hai to meri cost kya hogi 
        int limit=0;
        while(start<=end)
        {
            long long int mid=start+(end-start)/2;
            // cout<<"is"<<mid<<endl;
            if(ispos(mid,inventory,orders))
            {
                // cout<<"mis is"<<mid<<endl;
                limit=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        limit++;
        for(auto i:inventory)
        {
            if(orders>0)
            {
                long long terms=min((long long)(i-limit+1ll),(long long)orders);
                if(terms>=0)
                {
                    ans+=terms*(2*i-terms+1ll)/2ll;
                    ans%=mod;
                    orders-=terms;
                }
            }
            else
            {
                break;
            }
        }
        for(int i=0;i<orders;i++)
        {
            ans+=limit-1;
            ans%=mod;
        }
        
        return ans%mod;
        
    }
};