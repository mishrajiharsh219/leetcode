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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
           multimap<int, ListNode*>m;
        for(auto &it : lists){
            ListNode *head = it;
            while(head){
                m.insert(pair{head->val, head});
                head = head->next;
            }
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for(auto &it : m){
            tail->next = it.second;
            tail = it.second;
        }
        return dummy->next;
    }
};