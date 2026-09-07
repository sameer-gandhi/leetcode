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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* pre=head;
        while(temp!=nullptr){
            if(temp->val==pre->val){
                pre->next=temp->next;
                temp=temp->next;
            }
            else{
                pre=temp;
                temp=temp->next;
            }
        }
    return head;
    }
};