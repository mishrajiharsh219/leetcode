class RandomizedSet {
public:
    vector<int> num;
    unordered_map<int,int> mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
     num.emplace_back(val);
        mp[val]=num.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        int ind=mp[val];
        mp[num[num.size()-1]]=ind;
        swap(num[ind],num[num.size()-1]);
        num.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
       return num[rand() % num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */