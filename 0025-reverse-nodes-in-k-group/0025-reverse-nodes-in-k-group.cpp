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
    void reverse(ListNode* start,ListNode* end){
        ListNode *prev=NULL,*cur=start,*n=start->next; 
         
        while(prev!=end){
         cur->next=prev;
        prev=cur;
        cur=n;
        if(n->next)
            n=n->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
     if(head==NULL or head->next==NULL or k==1)
         return head;
    ListNode* start=head,*end=head;
    int shift=k-1;
        while(shift--){
            end=end->next;
            if(end==NULL)
            return head;
        }
      ListNode* nexthead= reverseKGroup(end->next,k);
      reverse(start,end);
      start->next=nexthead; 
      return end;
    }
};