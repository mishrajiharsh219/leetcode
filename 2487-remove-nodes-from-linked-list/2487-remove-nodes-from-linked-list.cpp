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
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* prev=NULL,*curr=head,*next=head->next;
        while(curr)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next)
                next=next->next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL)
            return head;
        ListNode* m=reverse(head);
        ListNode* newhead=m;
        ListNode* p=new ListNode(-1);
        ListNode* ans=p;
        int maxi=-1;
        while(newhead)
        {
            if(newhead->val>=maxi){
                ans->next=newhead;
                ans=ans->next;
                maxi=max(maxi,newhead->val);
                newhead=newhead->next;
                if(newhead==NULL)
                    break;
            }
            else{
                if(newhead->next==NULL)
                    break;
                newhead=newhead->next;
                
            }
        }
         ans->next=NULL;
        ListNode* org=reverse(p->next);
        return org;
    }
};