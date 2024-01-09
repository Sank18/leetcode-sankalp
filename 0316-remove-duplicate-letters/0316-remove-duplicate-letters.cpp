class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_map<char,int>umap;
        unordered_map<char,bool>seen;
        for(int i=0;i<s.size();i++)
        {
            umap[s[i]]=i;
        }
        for(int i=0;i<s.size();i++)
        {
            if(seen[s[i]]==true)
            {
                continue;
            }
            if(st.empty())
            {
                st.push(s[i]);
                seen[s[i]]=true;
                
            }
            else
            {
                while( st.empty()==false && st.top()>=s[i] && umap[st.top()]>=i)
                {
                    seen[st.top()]=false;
                    st.pop();
                    
                    
                }
                st.push(s[i]);
                seen[st.top()]=true;
            }
        }
        string ans="";
        
        while(!st.empty())
        {
        
                ans+=st.top();
            
            
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};