class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        queue<int>q;
        q.push(0);
        int k=0;
        int n=s.size();
        vector<int>vis(n,0);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            if(curr==(n-1))
            {
                return true;
            }
            for(int i=max(k,curr+minJump);i<=min(curr+maxJump,n-1);i++)
            {
                if(s[i]=='0' && vis[i]==0)
                {
                    q.push(i);
                    vis[i]=1;
                }
            }
            k=curr+maxJump;
        }
        return false;
        
    }
};