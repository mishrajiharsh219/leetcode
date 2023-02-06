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
        ListNode* prev=NULL,*curr=head,*nex=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex)
                nex=nex->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        ListNode*a=head;
        ListNode*b=slow->next;
        bool flag=true;
        while(b!=NULL){
            if(a->val!=b->val)
            {
                flag=false;
                break;
            }
            a=a->next;
            b=b->next;
        }
        slow->next=reverse(slow->next);
        return flag;
    }
};