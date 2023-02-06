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
    ListNode* removeElements(ListNode* head, int value) {
        if(head==NULL)
            return NULL;
        ListNode* newhead=new ListNode(-1);
        newhead->next=head;
        ListNode* prev=newhead,*curr=head;
        while(curr){
            if(curr->val==value){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return newhead->next;
    }
};