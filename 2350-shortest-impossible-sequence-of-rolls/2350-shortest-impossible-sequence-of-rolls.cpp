class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int>st;
        int len=0;
        for(int i=0;i<rolls.size();i++)
        {
            st.insert(rolls[i]);
            if(st.size()==k)
            {
                //hey i got all the starting 
                len++;
                //alll length of len is possible;
                st.clear();
            }
        }
        return len+1;
        
    }
};