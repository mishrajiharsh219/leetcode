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
    int size(ListNode* head){
        int s=0;
        while(head){
            head=head->next;
            s++;
        }
        return s;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL or head->next==NULL)
            return head;
        int n=size(head);
   
        ListNode* newhead=new ListNode(-1);
         newhead->next=head;
        ListNode* org=newhead;
        ListNode* newend=new ListNode(-1);
        while(org->next){
            org=org->next;
        }
        org->next=newend;
        
        ListNode* prev1=newhead,*prev2=newhead,*temp1,*temp2,*next1,*next2;
        int firstshift=k-1;
        int secondshift=n-k;
        while(firstshift--){
            prev1=prev1->next;
        }
        while(secondshift--){
            prev2=prev2->next;
        }
        temp1=prev1->next;
        temp2=prev2->next;
        next1=prev1->next->next;
        next2=prev2->next->next;
        
        //edge case if both elements are adjacent
        
        if(temp1->next==temp2){
         prev1->next=temp2;   
         temp2->next=temp1;
        temp1->next=next2;
        }
        else if(temp2->next==temp1){
             prev2->next=temp1;   
         temp1->next=temp2;
        temp2->next=next1;
        }
        else{
        prev1->next=temp2;
        temp2->next=next1;
        prev2->next=temp1;
        temp1->next=next2;
        }
        ListNode* ptr=newhead;
        while(n--){
            ptr=ptr->next;
        }
        ptr->next=NULL;
        return newhead->next;
    }
};