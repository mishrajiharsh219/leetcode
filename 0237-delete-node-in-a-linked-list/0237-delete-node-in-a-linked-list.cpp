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
    void deleteNode(ListNode* node) {
        if(node->next==NULL)
            delete node;
        int temp=node->val;
        int temp2=node->next->val;
        node->next->val=temp;
        node->val=temp2;
        ListNode* temp3=node->next;
        node->next=temp3->next;
        delete temp3;
    }
};