class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int mid=n/2;
        int i=0;
        int j=mid;
        int count1=0;
        int count2=0;
        string vowels="aeiouAEIOU";
        while(i<mid && j<n)
        {
            if(vowels.find(s[i])!=string::npos)
            {
                count1++;
            }
            if(vowels.find(s[j])!=string::npos)
            {
                count2++;
            }
            i++;
            j++;
        }
        return count1==count2;
        
    }
};