class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
    }
    bool insert(int val) {
        if(st.find(val)==st.end()){
            st.insert(val);
            return true;
        }
        else
            return false;
    }
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            st.erase(val);
            return true;
        }
        else
            return false;
    }
    int getRandom() {
        if(st.size()!=0){
            return *next(st.begin(),rand()%st.size());               
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */