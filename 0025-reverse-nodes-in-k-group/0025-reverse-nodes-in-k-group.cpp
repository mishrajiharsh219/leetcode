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
        
   ListNode* dummy=new ListNode(-1);
   dummy->next=head;
   ListNode *beforestart=dummy,*end=head;
   int i=0;
        while(end!=NULL){
       i++;
       if(i%k==0){
           ListNode* start=beforestart->next,*temp=end->next;
           reverse(start,end);
           beforestart->next=end;
           start->next=temp;
           beforestart=start;
           end=temp;
       }
       else{
           end=end->next;
       }
   }
        return dummy->next;
    }
};