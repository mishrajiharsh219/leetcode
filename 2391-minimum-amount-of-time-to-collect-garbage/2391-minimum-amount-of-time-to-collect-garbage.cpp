class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       long long int ans=0;
        int lastmetal=0,lastpaper=0,lastglass=0;
        int count=0;
        for(int i=0;i<garbage.size();i++){
            for(auto c: garbage[i]){
            if(c=='G'){
            lastglass=i;
                count++;
           }
            }
             for(auto c: garbage[i]){
            if(c=='M'){
            lastmetal=i;
                 count++;}
           }
             for(auto c: garbage[i]){
            if(c=='P'){
            lastpaper=i;
                count++;
            }
           }
        }
    for(int i=0;i<lastglass;i++){
        ans+=travel[i];
    }
          for(int i=0;i<lastmetal;i++){
        ans+=travel[i];
    }
          for(int i=0;i<lastpaper;i++){
        ans+=travel[i];
    }
        ans+=count;
        
        
        return ans;
        
    }
};