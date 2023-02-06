/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        int l=0;
        while(head!=NULL){
            l++;
            head=head->next;
        }
        return l;
    }
    ListNode* move(ListNode* head,int m){
        while(m--){
            head=head->next;
        }
        return head;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        int la=length(headA);
        int lb=length(headB);
        if(la>lb){
            headA=move(headA,la-lb);
        }
        else{
            headB=move(headB,lb-la);
        }
         ListNode*a=headA;
        ListNode*b=headB;
        while(a!=NULL){
            if(a==b)
                return a;
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};