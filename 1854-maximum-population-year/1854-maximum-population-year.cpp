class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int line[2051]={0};
        for(auto it:logs)
        {
            line[it[0]]++;
            line[it[1]]--;
        }
        int ans=INT_MIN;
        int count=0;
        int year;
        for(int i=1950;i<=2050;i++)
        {
            count+=line[i];
            if(count>ans)
            {
                ans=count;
                year=i;
            }
        }
        return year;
    }
};