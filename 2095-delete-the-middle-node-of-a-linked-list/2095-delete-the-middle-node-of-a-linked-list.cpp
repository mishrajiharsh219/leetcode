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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
            return NULL;
        if(head->next->next==NULL)
        {
            head->next=NULL;
            return head;
        }
        int length=0;
        ListNode *start=head;
        ListNode *temp= head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        int mid=floor(length/2);
        mid=mid-1;
        ListNode* temp2=start;
        while(mid--){
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        return start;
    }
};