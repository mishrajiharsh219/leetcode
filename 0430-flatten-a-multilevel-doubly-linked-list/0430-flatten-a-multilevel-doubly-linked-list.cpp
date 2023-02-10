/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return NULL;
        Node* ptr=head;
        while(ptr!=NULL){
            if(ptr->child){
                Node* realnext=ptr->next;
                Node* children=flatten(ptr->child);
                ptr->next=children;
                ptr->child=NULL;
                children->prev=ptr;
                Node* lastnode=children;
                while(lastnode->next){
                    lastnode=lastnode->next;
                }
                lastnode->next=realnext;
                if(realnext)
                realnext->prev=lastnode;
            }
            ptr=ptr->next;
        }
        return head;
    }
};