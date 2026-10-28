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
    void connectcopyNodes(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
    }

    void connectRandomNodes(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy=temp->next;
            if(temp->random!=nullptr){
                copy->random=temp->random->next;
            }
            else{
                copy->random=nullptr;
            }
            temp=temp->next->next;
        }
    }
    Node* connectNextpointer(Node* head){
        Node* temp=head;
        Node* dummy=new Node(-1);
        Node* mover=dummy;
        while(temp!=nullptr){
            mover->next=temp->next;
            mover=mover->next;
            temp->next=mover->next;
            temp=temp->next;
        }
        mover=dummy->next;
        delete(dummy);
        return mover;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return head;
        }
        connectcopyNodes(head);
        connectRandomNodes(head);
        return connectNextpointer(head);
    }
};