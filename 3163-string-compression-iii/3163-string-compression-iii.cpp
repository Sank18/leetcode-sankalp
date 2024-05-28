class Solution {
public:
    string compressedString(string word) {
        int start=0;
        int end=1;
        if(word.size()==1)
        {
            string ans='1'+word;
            return ans;
        }
        string ans="";
        int count=0;
        int newind=0;
        for(int i=0;i<word.size();i++)
        {
            count=0;
            newind=0;
            for(int j=i;j<word.size() && word[i]==word[j];j++)
            {
                count++;
                
                newind=j;
                if(count==9)
                {
                    break;
                }
            }
            ans+=to_string(count)+word[i];
            i=newind;
        }
        return ans;
    }
};