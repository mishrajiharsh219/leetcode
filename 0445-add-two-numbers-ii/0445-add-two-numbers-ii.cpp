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
    ListNode* reverse(ListNode* head){
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* pre=NULL, *curr=head,*n=head->next;
        while(curr){
            curr->next=pre;
            pre=curr;
            curr=n;
            if(n!=NULL)
                n=n->next;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* l1=reverse(list1);
        ListNode* l2=reverse(list2);
        
        ListNode* newhead=new ListNode(-1);
        ListNode* org=newhead;
        int extra=0;
        while(l1 or l2 or extra){
            int ans= (l1?l1->val:0)+(l2?l2->val:0)+extra;
            int now=ans%10;
             newhead->next=new ListNode(now);
             extra=ans/10;
            newhead=newhead->next;
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }
        org->next=reverse(org->next);
        return org->next;
    }
};