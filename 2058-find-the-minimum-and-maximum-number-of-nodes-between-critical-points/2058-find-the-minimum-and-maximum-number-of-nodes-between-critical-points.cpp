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
    bool critical(ListNode* prev,ListNode* head,ListNode* next){
        if(head->val>prev->val and head->val>next->val)
            return true;
        else if (head->val<prev->val and head->val<next->val)
            return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL or head->next==NULL or head->next->next==NULL)
            return {-1,-1};
        int maxlen=0;
        int minlen=INT_MAX;
       int prevind=0,nextind=0,first=0,last=0;
        ListNode* prev=head;
         head=head->next;
        ListNode* nexx=head->next;
        bool flag=false;
        int counter=0;
        while(head->next){
            if(flag==false and critical(prev,head,nexx)){
                first=counter,prevind=counter,nextind=counter,last=counter;
                maxlen=max(maxlen,last-first);
                minlen=min(minlen,nextind-prevind);
                flag=true;
            }
            else if(critical(prev,head,nexx)){
                nextind=counter;
                last=counter;
                maxlen=max(maxlen,last-first);
                if(minlen==0)minlen=INT_MAX;
                minlen=min(minlen,nextind-prevind);
                prevind=counter;
            }
                 prev=head;
                 head=head->next;
                 if(head->next==NULL)
                    break;
                nexx=head->next;
                counter++;
        }
        if(minlen==0 or maxlen==0)
         return {-1,-1};   
        return {minlen,maxlen};
    }
};