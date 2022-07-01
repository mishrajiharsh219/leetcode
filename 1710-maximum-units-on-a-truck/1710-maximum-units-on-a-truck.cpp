class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        if(v1[1]>v2[1])return true;
        else
            return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int trucksize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int maxsize=0;
        int ans=0,i=0;
        for(int i=0;i<boxTypes.size();i++){
         
           maxsize+=boxTypes[i][0]; 

}
        if(maxsize<trucksize)
        {
           for(int i=0;i<boxTypes.size();i++){
         
           ans+=boxTypes[i][0]*boxTypes[i][1];

           } 
            return ans;
        }
        
        while(trucksize>0){
            if(boxTypes[i][0]<trucksize){
            ans+=boxTypes[i][0]*boxTypes[i][1];
             trucksize=trucksize-boxTypes[i][0];}
            else{
                 ans+=trucksize*boxTypes[i][1];
                trucksize=0;
            }
            i++;
           
        }
        return ans;
    }
};