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
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        
        while(left and right){
        if(left->val<right->val){
           temp->next=left;
            temp=temp->next;
            left=left->next;
        }   
        else
        {
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        }
        
        while(left!=NULL)
        {
          temp->next=left;
            temp=temp->next;
            left=left->next;   
            
        }
        while(right!=NULL)
        {
           temp->next=right;
            temp=temp->next;
            right=right->next;       
        }
        temp->next=NULL;
        ans=ans->next;
        return ans;
    }
  void print(ListNode* head){
        while(head){
            cout<<head->val;
            head=head->next;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* lefty=head;
        ListNode* mid=middle(head);
        ListNode* righty=mid->next;
        mid->next=NULL;
     
        ListNode* left=sortList(lefty);
        ListNode* right=sortList(righty);
      
        ListNode* ans=merge(left,right);
        return ans;
    }
};