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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int n=size(head);
        int sizeeach=n/k;
        int extra=n%k;
        vector<int> finalsize(k,sizeeach);
        for(int i=0;extra>0;i++){
            finalsize[i]++;
            extra--;
        }
        for(int i=0;i<k;i++){
            if(finalsize[i]==0)
            { res.push_back(NULL);
             continue;
            }
           ListNode* temphead=head,*org=temphead;
            int sized=finalsize[i]-1;
            while(sized--){
                if(temphead->next)
                temphead=temphead->next;
            }
            head=temphead->next;
            temphead->next=NULL;
            res.push_back(org);
        }
        return res;
    }
};