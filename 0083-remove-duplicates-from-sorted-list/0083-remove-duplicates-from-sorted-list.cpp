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
    ListNode* deletedup(ListNode* head){
   if(head->next==NULL)
            return head;
        ListNode* temp=deletedup(head->next);
     if(temp->val==head->val)
         return temp;
        head->next=temp;
     return head;
         
    }
    ListNode* deleteDuplicates(ListNode* head) {
          if(head==NULL)
        return NULL;
        if(head->next==NULL)
            return head;
        return deletedup(head);
    }
};