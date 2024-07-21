class Solution {
public:
    int maxOperations(string s) 
    {   
        string s1 = "";
        int count = 0, one = 0;

        
        s1 += s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '1')
                s1 += s[i];
            else 
            {
                if (s[i] != s[i-1])
                    s1 += s[i];
            }
        }

      
        for (char x : s1)
        {
            if (x == '1')
                one++;
            else 
            {
                count += one;
            }
        }

        return count;
    }
};