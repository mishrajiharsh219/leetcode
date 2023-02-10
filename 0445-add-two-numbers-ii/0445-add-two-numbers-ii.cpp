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
            s++;
            head=head->next;
        }
        return s;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1=size(l1);
        int s2=size(l2);
        ListNode* res=NULL;
        ListNode* n=NULL;
        while(l1 or l2){
            int v1=0,v2=0;
         if(s1>=s2)   
         {
             v1+=l1?l1->val:0;
             l1=l1->next;
             s1--;
         }
         if(s2>=s1+1){
             v2+=l2?l2->val:0;
             l2=l2->next;
             s2--;
         }  
        n= new ListNode(v1+v2);
       n->next=res;
       res=n;
        }
       int carry = 0;
    res = NULL;
    // Now, let's perform the normalization.
    while (n != NULL) {
        n->val += carry;
        if (n->val >= 10) {
            n->val = n->val % 10;
            carry = 1;
        } else {
            carry = 0;
        }
        ListNode* buf = n->next;
        n->next = res;
        res = n;
        n = buf;
    }
    if (carry > 0) {
        n = new ListNode(1);
        n->next = res;
        res = n;
    }
    return res;
        
    }
};