class RandomizedSet {
public:
    unordered_map<int, int>mm;
    vector<int>v;
    int sz;
    RandomizedSet() {
        sz = 0;
    }
    
    bool insert(int val) {
        if(mm.count(val))return false;
        mm[val] = sz;
        v.push_back(val);
        sz++;
        return true;
    }
    
    bool remove(int val) {
        if(!mm.count(val))return false;
        int idx =  mm[val];
        v[idx] = v[sz - 1];
        v.pop_back();
        mm[v[idx]] = idx;
        mm.erase(val);
        sz--;
        return true;
    }
    
    int getRandom() {
        return v[rand()%sz];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */