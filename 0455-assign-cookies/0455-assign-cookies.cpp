class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int count=0;
        while(i<g.size() && j<s.size())
        {
            int index=lower_bound(s.begin()+j,s.end(),g[i])-s.begin();
            cout<<index<<endl;
            if(index>=s.size())
            {
                return count;
            }
            else
            {
                count++;
                j=index+1;
            }
            i++;
        }
        return count;
        
    }
};