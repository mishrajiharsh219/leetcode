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
    ListNode* mergeNodes(ListNode* head) {
       if(head==NULL or head->next==NULL)
           return head;
        if(head->val==0 and head->next->val==0)
            return NULL;
        ListNode* ans=new ListNode(-1),*org=ans;
        ans->next=head;
        ListNode *temp=head->next;
        long long int sum=0;
        while(temp){
            if(temp->val==0){
                ans->next->val=sum;
                ans=ans->next;
                sum=0;
                temp=temp->next;
            }
            else{
            sum+=temp->val;
                temp=temp->next;}
        }
        ans->next=NULL;
        return org->next;
    }
};