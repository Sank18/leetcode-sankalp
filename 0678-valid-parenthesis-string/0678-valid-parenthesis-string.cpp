class Solution {
public:
    bool checkValidString(string s) {
        stack<int>para;
        stack<int>star;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                para.push(i);
            }
            if(s[i]=='*')
            {
                star.push(i);
            }
            if(s[i]==')')
            {
                if(!para.empty())
                {
                    para.pop();
                }
                else if(!star.empty())
                {
                    star.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while(!para.empty() && !star.empty())
        {
            if(para.top()>star.top())
            {
                return false;
            }
            star.pop();
            para.pop();
        }
        if(para.size()==0)
        {
            return true;
        }
        return false;
        
    }
};