class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		int start = 1, end = *max_element(nums.begin(), nums.end());
		int minPenalty = end;
		// binary search on possible range
		while (start <= end) {
			int penalty = start + (end-start)/2;
			if (isPossible(nums, maxOperations, penalty))
				minPenalty = penalty, end = penalty-1;
			else
				start = penalty+1;
		}

		return minPenalty;
	}

	bool isPossible(vector<int>& nums, int maxOperations, int penalty) {
		int requiredOps = 0;
		for (int n : nums) {
			// no. of operations required to bring n less than or eq to curr assumed penalty
			int x = n / penalty;
			// if n is divisible by penalty, need to subtract 1
			if (n % penalty == 0) x--;
			requiredOps += x;
		}
		// getting current penalty is possible only if required ops is <= maxOps
		return requiredOps <= maxOperations;
	}
};