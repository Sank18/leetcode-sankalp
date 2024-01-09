class Solution {
public:
    static bool cmp(char a,char b)
    {
        return a<b;
    }
    static bool cmp1(char a,char b)
    {
        return a>b;
    }
    long long smallestNumber(long long num) {
        if(num>0)
        {
            string s1=to_string(num);
            sort(s1.begin(),s1.end(),cmp);
            int i=0;
            int k=0;
            if(s1[0]=='0')
            {
                for(int j=0;j<s1.size();j++)
                {
                    if(s1[j]!='0')
                    {
                        k=j;
                        break;
                    }
                }
            }
           swap(s1[i],s1[k]);
            long long ans=stol(s1,nullptr,10);
            return ans;
            
        }
        string s2=to_string(-1*num);
        sort(s2.begin(),s2.end(),cmp1);
        long long ans=stol(s2,nullptr,10);
        return -1*ans;
        
      
        
    }
};