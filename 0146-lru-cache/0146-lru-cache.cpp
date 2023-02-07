class LRUCache {
public:
    list<int> l;
    unordered_map<int,int> mp;
    unordered_map<int,list<int>::iterator> address;
    int size;
    int cap;
    LRUCache(int capacity) {
     size=0;
    cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        auto it=address[key];
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key]=l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]=value;
            int ans=key;
            auto it=address[key];
            l.erase(it);
            address.erase(key);
            l.push_front(ans);
            address[key]=l.begin();
            return;
        }
        if(size==cap){
            int k=l.back();
            l.pop_back();
            mp.erase(k);
            address.erase(k);
            size--;
        }
        size++;
        mp[key]=value;
        l.push_front(key);
        address[key]=l.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */