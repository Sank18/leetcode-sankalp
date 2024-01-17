class NumArray {
public:
    vector<int>arr;
    vector<int>tree;
    int n;
    void build(int node,int start,int end)
    {
        if(start==end)
        {
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
        return;
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr=nums;
        tree.resize(4*n);
        build(1,0,n-1);
        
    }
    
    int querry(int node,int start,int end,int l,int r)
    {
        if(start>r || end<l)
        {
            return 0;
        }
        if(l<=start && r>=end)
        {
            return tree[node];
        }
        int mid=start+(end-start)/2;
        int q1=querry(2*node,start,mid,l,r);
        int q2=querry(2*node+1,mid+1,end,l,r);
        return q1+q2;
    }
    void up(int node,int start,int end,int index,int val)
    {
        if(index<start ||index>end)
        {
            return ;
        }
        if(start==end)
        {
            arr[start]=val;
            tree[node]=val;
            return;
        }
        int mid=start+(end-start)/2;
        if(index<=mid)
        {
            up(2*node,start,mid,index,val);
        }
        else
        {
            up(2*node+1,mid+1,end,index,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
        return;
    }
    void update(int index, int val) {
        up(1,0,n-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
        return querry(1,0,n-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */