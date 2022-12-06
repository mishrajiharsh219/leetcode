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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* temp=head;
        ListNode* orgtemp=head;
        ListNode* temp2=head->next;
        ListNode* orgtemp2=head->next;
        while(temp->next and temp2->next){
            if(temp->next->next){
            temp->next=temp->next->next;
            temp=temp->next;}
            if(temp2->next->next){
            temp2->next=temp2->next->next;
            temp2=temp2->next;
            }
        }
        temp->next=NULL;
        temp2->next=NULL;
        temp->next=orgtemp2;
        return orgtemp;
    }
};