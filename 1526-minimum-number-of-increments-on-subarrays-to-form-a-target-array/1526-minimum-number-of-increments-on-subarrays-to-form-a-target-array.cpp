class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int count=target[0];
        stack<int>st;
        st.push(target[0]);
        //st top represnts number of move available with me
        for(int i=1;i<target.size();i++)
        {
            //i have enough moves to make the new building 
            if(target[i]<=st.top())
            {
                //ourmoves gets updated 
                st.push(target[i]);
            }
            else
            {
                //i dont have enough moves to make the current building
                count=count+target[i]-st.top();
                st.push(target[i]);
                //new moves available updated
            }
        }
        return count;
    }
};