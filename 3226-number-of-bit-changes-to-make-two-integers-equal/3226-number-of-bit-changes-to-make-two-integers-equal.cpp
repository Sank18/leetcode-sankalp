class Solution {
public:
    int minChanges(int n, int k) {
        int mask=1;
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int bit1=(n&mask);
            int bit2=(k & mask);
            cout<<bit1<<" "<<bit2<<endl;
            n= (n>>1);
            k=(k>>1);
            if(bit1==bit2)
            {
                continue;
            }
            if(bit1!=bit2 && bit1!=1)
            {
                return -1;
            }
            ans++;
            
        }
        return ans;
        
    }
};