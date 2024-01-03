class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>levels;
        int n=bank.size();
        int m=bank[0].size();
        for(int i=0;i<n;i++)
        {
            int pref=0;
            for(int j=0;j<m;j++)
            {
                if(bank[i][j]=='1')
                {
                    pref++;
                }
            }
            levels.push_back(pref);
        }
        int ans=0;
        int l=levels.size();
        for(int i=0;i<l;i++)
        {
            if(levels[i]==0)
            {
                continue;
            }
            for(int j=i+1;j<l;j++)
            {
                if(levels[j]!=0)
                {
                    ans+=(levels[i]*levels[j]);
                    break;
                }
            }
        }
        return ans;
        
        
    }
};