class RangeFreqQuery {
public:
    unordered_map<int,vector<int>>umap;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
        {
             umap[arr[i]].push_back(i);
        }
        
    }
    
    int query(int left, int right, int value) {
        return upper_bound(umap[value].begin(),umap[value].end(),right)-lower_bound(umap[value].begin(),umap[value].end(),left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */