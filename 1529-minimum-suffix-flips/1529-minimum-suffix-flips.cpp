class Solution {
public:
    int minFlips(string target) {
        string news="";
        
        news+=target[0];
        for(int i=1;i<target.size();i++)
        {
            if(news[news.size()-1]!=target[i])
            {
                news+=target[i];
            }
            
        }
       if(news.size()==1 && news[0]=='0')
        {
            return 0;
        }
        if(news[0]=='0')
        {
            return news.size()-1;
        }
        return news.size();
        
    }
};