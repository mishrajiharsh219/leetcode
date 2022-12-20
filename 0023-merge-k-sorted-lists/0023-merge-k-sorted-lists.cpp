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
   
    class cmp{
         public:
      bool operator()(ListNode* l1,ListNode* l2){
        return l1->val>l2->val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& list) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for(int i=0;i<list.size();i++){
            if(list[i]!=NULL)
            q.push(list[i]);
        }
        ListNode* ans=new ListNode(-1);
        ListNode* tail=ans;
        while(!q.empty())
        {
        ListNode* temp=q.top();
        q.pop();
        tail->next=temp;
        tail=temp;
        if(temp->next!=NULL)
            q.push(temp->next);
        }
        return ans->next;
    }
};