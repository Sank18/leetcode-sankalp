class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks=1;
        
        vector<int>intervalmax;
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>=maxi)
            {
                //i can do partition
                intervalmax.push_back(maxi);
                // cout<<"did a partition at "<<" "<<st.top()<<endl;
                
                maxi=arr[i];
            }
            else
            {
                //i cant do partition ,i have to add to the current part 
                
                    //it is not crerating a problem in previous parts
                    bool flag=false;
                    //false represnts not creating a problem
                    int breakingpoint=100000;
                    for(int j=0;j<intervalmax.size();j++)
                    {
                        if(arr[i]<intervalmax[j])
                        {
                            breakingpoint=j;
                            flag=true;
                            break;
                        }
                    }
                
                if(flag==false)
                {
                    continue;
                }
                else
                {
                    // cout<<"gave to merge all till partition having max value as"<<intervalmax[breakingpoint]<<endl;
                    int n=intervalmax.size();
                    for(int j=n-1;j>=breakingpoint;j--)
                    {
                        intervalmax.pop_back();
                    }
                    
                    chunks=intervalmax.size()+1;
                }
                
            }
        }
        return intervalmax.size()+1;
        
    }
};