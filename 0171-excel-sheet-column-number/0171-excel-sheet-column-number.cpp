class Solution {
public:
    int titleToNumber(string c) {
        int result=0;
        for(int i=0;i<c.size();i++)
        {
            int d=c[i]-'A'+1;
            result=result*26+d;
        }
        return result;
        
    }
};