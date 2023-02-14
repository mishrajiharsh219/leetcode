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
        int n=0;
        while(head){
            n++;
            head=head->next;
        }
        return n;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int n=length(head);
        // cout<<n;
        ListNode* node=head;
        for(int k=1;n;k++){
            int grpsize=min(k,n); //beacuse last grpsize can be less than k
            stack<int> st;
            if(grpsize%2==0){
            ListNode* temp=node;
            for(int i=0;i<grpsize;i++){
                st.push(temp->val);
                temp=temp->next;
            }
            }
             for(int i=0;i<grpsize;i++){
               if(st.size()){
                   node->val=st.top();
                   st.pop();
               }
                 //node moves k times
                   node=node->next;
               }
           n-=grpsize; 
        }
        return head;
    }
};