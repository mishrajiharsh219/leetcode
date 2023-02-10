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
    int length(ListNode* head){
        int s=0;
        while(head){
            s++;
            head=head->next;
        }
        return s;
    }
    void reorderList(ListNode* head) {
        int org=length(head);
        if(org<3)
            return;
        stack<ListNode*> s;
        ListNode* ptr=head;
        while(ptr){
            s.push(ptr);
            ptr=ptr->next;
        }
        int currsize=1;
        ListNode* newhead=head;
        ListNode* n=head->next;
       while(currsize<org){
           if(currsize%2!=0){
               newhead->next=s.top();
               newhead=newhead->next;
               s.pop();
               currsize++;
           }
           else{
               newhead->next=n;
               newhead=newhead->next;
               n=n->next;
               currsize++;
           }
       }
        newhead->next=NULL;
    }
};