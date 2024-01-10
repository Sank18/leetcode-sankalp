class Solution {
public:
    int minSwaps(string s) {
        int open=0;
        int closed=0;
        
        set<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                st.insert(i);
            }
        }
        int swaped=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                open++;
            }
            else
            {
                closed++;
                if(closed>open)
                {
                    swaped++;
                    if(!st.empty())
                    {
                        int index=*st.rbegin();
                        if(index>i)
                        {
                            swap(s[index],s[i]);
                            open++;
                            closed--;
                            st.erase(index);
                        }
                    }
                }
            }
        }
        return swaped;
            
        
    }
};