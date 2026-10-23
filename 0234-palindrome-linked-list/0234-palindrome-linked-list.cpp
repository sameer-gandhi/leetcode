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
    ListNode* reverseLL(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* pre=nullptr;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* front=temp->next;
            temp->next=pre;
            pre=temp;
            temp=front;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newhead=reverseLL(slow->next);
        slow=newhead;
        fast=head;
        while(slow!=nullptr){
            if(slow->val!=fast->val){
                reverseLL(newhead);
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        reverseLL(newhead);
        return true;
    }
};