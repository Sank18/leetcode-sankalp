class Solution {
public:
    bool doesAliceWin(string s) {
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(st.find(s[i])!=st.end())
            {
                count++;
            }
        }
        if(count==0)
        {
            return false;
        }
        return true;
        
    }
};