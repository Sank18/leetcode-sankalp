class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>temp=deck;
        sort(temp.begin(),temp.end());
        deque<int>q;
        q.push_back(temp[n-1]);
        int flag=false;
        for(int i=n-2;i>=0;i--)
        {
            if(flag==false)
            {
                q.push_front(q.back());
                q.pop_back();
                flag=true;
            }
            if(flag==true)
            {
                q.push_front(temp[i]);
                flag=false;
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
        
    }
};