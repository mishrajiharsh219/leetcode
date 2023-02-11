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
        ListNode* prev= NULL,*curr=head,*next=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next){next=next->next;}
        }
        return prev;
    }
    int length(ListNode* head){
        int s=0;
        while(head){
            s++;
            head=head->next;
        }
        return s;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL)
            return head;
        int size=length(head);
        k=k%size;
        ListNode* first=head,*second=head,*firstend=head;
        int tempsize=size-k;
        while(tempsize--){
            firstend=second;
            second=second->next;
        }
        firstend->next=NULL;
        ListNode* l1=reverse(first);
        ListNode* l2=reverse(second);
        
        ListNode* newfirstend=l1;
        while(head){
            newfirstend=head;
            head=head->next;
        }
        newfirstend->next=l2;
        ListNode* ans=reverse(l1);
        return ans;
    }
};