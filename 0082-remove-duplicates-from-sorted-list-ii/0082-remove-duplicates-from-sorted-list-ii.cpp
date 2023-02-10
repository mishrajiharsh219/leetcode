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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* prev=new ListNode(-101);
        ListNode* newhead=prev;
        prev->next=head;
        ListNode* curr=head;
        bool falg=false;
        while(curr){
            if(curr->next==NULL and falg==true)
            {
                prev->next=curr->next;
                break;
            }
            if(curr->next==NULL and falg==false)
                break;
            if(curr->next and curr->val!=curr->next->val and falg==false){
                prev=prev->next;
                curr=curr->next;
            }
            else if (curr->next and curr->val!=curr->next->val and falg==true){
                falg=false;
                prev->next=curr->next;
                curr=curr->next;
            }
            else if(curr->next and curr->val==curr->next->val){
                falg=true;
                curr=curr->next;
            }
        }
        return newhead->next;
    }
};