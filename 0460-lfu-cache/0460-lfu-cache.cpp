class LFUCache {
public:
        int cap;
        int minfreq;
        unordered_map<int,pair<int,int>> cache;     //{key->{value,freq}};
        unordered_map<int,list<int>::iterator> address;     //{key,address};
        unordered_map<int,list<int>> freqlist;       //freq->list of keys

    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
    }
    
    int get(int key) {
        //if key is not present
        if(cache.count(key)==0)
            return -1;
        
        updatefreq(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        //if max size of cache is 0
        if(cap<=0)
            return;
        //if key is already present then size will not be increased so direct update
        if(cache.count(key)!=0){
            updatefreq(key);
            cache[key].first=value;
        }
        // key need to be inserted
        else{
            //capacity exceeds maxcapacity
            //if new element is inserted minfreq will always be 0
            if(cache.size()>=cap)
            {
            int leastfreqkey=freqlist[minfreq].back();
            cache.erase(leastfreqkey);
            address.erase(leastfreqkey);
            freqlist[minfreq].pop_back();
            }
            cache[key]={value,0};
            freqlist[0].push_front(key);
            address[key]=freqlist[0].begin();
            
            minfreq=0;
            }
    }
   private:
    void updatefreq(int key){
        int currfreq=cache[key].second;
        // increase the frequency in cache map
        cache[key].second++;
        //list always erases the addresses not values
        freqlist[currfreq].erase(address[key]);
        freqlist[currfreq+1].push_front(key);
        address.erase(key);
        address[key]=freqlist[currfreq+1].begin();
        // if minfreq's size becomes zero
        if(freqlist[minfreq].size()==0)
            //delete old minfreq from freqlist
        { freqlist.erase(minfreq);
         //new minfreq
        ++minfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */