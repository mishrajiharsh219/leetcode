/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void copylist(Node* head){
        Node* temp=head;
        Node* n=head->next;
        while(temp){
            Node* copy=new Node(temp->val);
            temp->next=copy;
            copy->next=n;
            temp=n;
            if(n!=NULL){n=n->next;}
        }
    }
    void handlerandom(Node* head){
        Node* temp=head;
        while(temp){
            if(temp->random)
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
    }
    Node* detach(Node* head){
       Node* temp=head;
        Node* copyhead=head->next;
        Node* tail=head->next;
        while(temp){
            temp->next=tail->next;
            if(temp->next)
                tail->next=temp->next->next;
            else
                tail->next=NULL;
            temp=temp->next;
            tail=tail->next;
        }
        return copyhead;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        copylist(head);
        handlerandom(head);
       return detach(head);
        
    }
};