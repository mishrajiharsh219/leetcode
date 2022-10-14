// "if we cut the sorted array to two halves of EQUAL LENGTHS, then
// median is the AVERAGE OF Max(lower_half) and Min(upper_half), i.e. the
// two numbers immediately next to the cut
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // if size of nums2 array is greater than nums1
        if(m > n) {
			// because we will use binary search search therefore starting with lower size of array
            return findMedianSortedArrays(nums2, nums1);
        }
		
        int s = 0, e = min(m,n);
        while(s<=e) {
			// find mid for first array
            int cut1 = s + (e-s)/2;
			// find mid for second array
            int cut2 = (n+m+1)/2 - cut1;
            
			/* if mid == 0 then assign MIN && MAX value accordingly
			to avoid errors while comparing for both arrays */
			
			// l1 and l2 are left element of mid or cut1
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
			//  r1 and r2 are right element or mid
            int r1 = cut1 == m ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n ? INT_MAX : nums2[cut2];
            
			// below condition means that both arrays are logically merged and sorted
            if(l1 <= r2 && l2 <= r1) {
				// if total no of elements of both arrays are even
                if((n+m)%2==0) {
                    return ((max(l1,l2) + min(r1,r2))/2.0);
                }
				// if elements are odd
                else return max(l1,l2);
            }
            else if(l2 > r1) {
                s = cut1+1;
            }
            else e = cut1-1;
        }
        return 0.0;
    }
};