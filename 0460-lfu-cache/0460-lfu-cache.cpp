class LFUCache {
    public:
    int capacity;  //max size of cache
    unordered_map<int, pair<int,int>> cache;   //{key->{value,freq}};      
    unordered_map<int, list<int>::iterator> address;     //key->address
    unordered_map<int,list<int>> freqMap;                 //freq->list of keys
    int minFreq=0;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)==0)
            return -1;
        
        updateFrequency(key);         
        return cache[key].first;
    }
    
    void put(int key, int value) 
    {
        if(this->capacity<=0) return;
        // if key is already in cache
        if(cache.count(key)!=0)
        {
            updateFrequency(key);            
            cache[key].first = value; //update value in cache
        }
        else
        {
            if(cache.size() >= this->capacity)
            {
                // remove last-element in the least-frequent-list, from cache
                int leastFrequentKey = freqMap[minFreq].back();
                cache.erase(leastFrequentKey);
                address.erase(leastFrequentKey);
                
                // remove least frequent from freqMap
                freqMap[minFreq].pop_back();
            } 
            
            // insert value and initialize frequency
            cache[key] = {value, 0};
            freqMap[0].push_front(key);
            address[key] = freqMap[0].begin();
            
            minFreq=0;// reset min frequency
        }
    }
    
    private:
    void updateFrequency(int key)
    {
        int freq = cache[key].second++;
        
        // remove from prev frequency list
        freqMap[freq].erase(address[key]);
        
        // append to updated frequency list
        freqMap[freq+1].push_front(key);
        
        //update list pointer to new list begin
        address[key] = freqMap[freq+1].begin();

        // remove empty lists incase minFrequency raises
         if(freqMap[minFreq].size()==0 ) 
           {
              freqMap.erase(minFreq++);
           }
    }
};