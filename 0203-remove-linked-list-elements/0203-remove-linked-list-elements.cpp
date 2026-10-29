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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr){
            return head;
        }
        ListNode* temp=head;
        ListNode* prenode=nullptr;
        while(temp!=nullptr){
            if(temp->val==val){
                if(temp==head){
                    head=head->next;
                }
                ListNode* nextnode=temp->next;
                if(prenode!=nullptr){
                    prenode->next=nextnode;
                }
                delete(temp);
                temp=nextnode;
            }
            else{
                prenode=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};