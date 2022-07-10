class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2;i<cost.size();i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};


//  def minCostClimbingStairs(self, cost: List[int]) -> int:
//         # identify what is changing from subproblems to subproblems: 
//         # n - step #n    dp(n) - min cost to get to step #n 
//         def dp(n):  
//             # write down base cases
//             if n < 2: 
//                 return cost[n] 
//             # write recursive function based on what you can change (climb one or two steps)
//             return cost[n] + min(dp(n-1), dp(n-2))
		
// 		# since we want to know the min cost to get to the final step, we use the code below 
//         length = len(cost) 
//         return min(dp(length-1), dp(length-2))