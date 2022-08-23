//can be solved using stack alse
//can be solved by fast and slow pointer also
//can be solves using recursion or temp array also
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      ListNode *fast=head,*slow=head,*temp,*prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        if(fast)
            slow=slow->next;
        else
            slow=slow;
        while(slow) // check if linked lists starting at prev and slow are equal
		if(slow -> val != prev -> val)
            return false;
		else
            slow = slow -> next, prev = prev -> next;
	return true;
    }
};