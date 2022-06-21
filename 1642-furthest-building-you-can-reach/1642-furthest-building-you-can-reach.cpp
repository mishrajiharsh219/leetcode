//we will use ladder when the difference btw h[i+1] and h[i] is max hence we check each time
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // Priority Queue for storing the bricks used in each step in decreasing order (Max at top)
        priority_queue<int> maxB;
    
        int i=0, diff =0; // i is used for storing the position and diff for storing difference.
        for(i=0; i<heights.size()-1; i++){ // go till before the last building.
            
            //difference of the height of corresponding buildings
            diff = heights[i+1]-heights[i];
            
            //If next building is equal or samaller than current then go to next building.
            if(diff <= 0){
                continue;
            }

            bricks -= diff; //taking the bricks needed for going to next building.
            maxB.push(diff); //adding the number of bricks used in priority queue.
            
            // if bricks become negetive then there were not enough bricks. So add a ladder in place of the step where most bricks were used.
            if(bricks < 0){
                bricks += maxB.top(); //taking back bricks from that step
                maxB.pop(); //As max bricks were removed so pop
                ladders--; //1 ladder used
            }

            //if ladder is negetive then the ladder was not provided to go to next building. So we can't proceed.
            if(ladders < 0) break;
        }
        
        // return the present position.
        return i;
    }
};
// // class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         int ans=0;
//         int br=0;
//      int i=1;
//         while(i<heights.size()){
//             if(heights[i]<=heights[i-1])
//             {i++;ans++;}
//             else if((heights[i]-heights[i-1])<=bricks)
//             {
//                 bricks=bricks-(heights[i]-heights[i-1]);
//                 ans++;i++;
//             }
//             else if(ladders>0)
//             {
//                 ladders--;
//                 ans++;
//                 i++;
//             }
//             else
//                 break;
//         }
//         return ans;
//     }
// };