/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         if(head == NULL)
            return false;
        
        ListNode* late=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            late=late->next;
            fast=fast->next->next;
  
        if(fast==late)
        return true;
        }
        return false;
    }
};