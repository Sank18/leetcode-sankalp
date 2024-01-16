class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        string s=countAndSay(n-1);
        string y="";
        int i=0;
        int j=0;
        while(i<s.size())
        {
            j=i;
            while(j<s.size() && s[i]==s[j])
            {
                j++;
            }
            int length=j-i;
            y+=to_string(length)+s[i];
            i=j;
        }
        return y;
        
    }
};