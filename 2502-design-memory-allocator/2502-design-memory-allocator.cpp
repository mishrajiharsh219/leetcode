class Allocator {
public:
    
    vector<int> v;
    Allocator(int n) {
        v.resize(n, 0);
    }
    
    int allocate(int size, int mID) {
        int start = -1, count = 0;
        for(int i = 0; i < v.size(); ++i){
            if(v[i] == 0){
                if(count == 0) start = i;
                count++;
                if(count >= size ) {
                    for(int j = 0; j < count; ++j){
                        v[start + j] = mID;
                    }
                    return start;
                }
            }else{
                start = -1;
                count = 0;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int sz = 0;
        for(int i=0; i < v.size(); ++i){
            if(v[i] == mID) {
                sz++;
                v[i] = 0;
            }
        }
        return sz;
    }
};
