class Solution { 
public: 
     bool isvalid(int n , int size)
    {
        
        for(int i = 0 ; i<=20 ; i++)
        {
            if( (n-size*i >=0) &&(n - (size*i)) % (size -1 ) == 0 )
                return true;
        }

        return 0;
    }
    int minGroupsForValidAssignment(vector<int>& nums) { 
        unordered_map<int ,int> mp;
        int n = nums.size();
        for(int i = 0 ; i<n; i++) 
            mp[nums[i]]++;
       
        vector<int> arr;
        for(auto ele:mp)
             arr.push_back(ele.second);
       
        int ss = *min_element(arr.begin() , arr.end());
        ss++;

         for(int size = ss; size>=1; size--)
        {
            bool check = true;
            // for(auto it:m)
            for(int i = 0 ; i<arr.size(); i++)
            {
                int fre = arr[i];
                if(isvalid(fre ,size) )
                {

                }
                else
                {
                    check  = 0;
                    break;
                }
            }
            if(check)
            { 
                int ans = 0; 
                // for(auto it: m)
                for(int i = 0 ; i<arr.size(); i++)
                { 
                     
                    int fre = arr[i]; 
                    int l = fre%size; 
                    ans += (fre/size); 
                    if(l > 0) ans++; 
                } 
                return ans; 
            }
        } 
            return -1; 

    } 
};