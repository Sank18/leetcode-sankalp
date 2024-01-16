class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>umap;
        for(auto it:s)
        {
            umap[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:umap)
        {
            pq.push({it.second,it.first});
        }
        pair<int,char>prev={-1,'#'};
        string curr="";
        while(!pq.empty())
        {
            pair<int,char>it=pq.top();
            pq.pop();
            curr=curr+it.second;
            if(prev.first>0)
            {
                pq.push(prev);
            }
            it.first--;
            prev=it;
        }
        cout<<curr<<endl;
        if(curr.size()==s.size())
        {
            return curr;
        }
        return "";
        
    }
};