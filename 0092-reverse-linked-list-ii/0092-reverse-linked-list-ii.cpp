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
        while(head!=nullptr){
            ListNode* next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        left=left-1;
        right=right-1;
        ListNode* leftnode=head;
        ListNode* rightnode=head;
        ListNode* preleft=nullptr;
        ListNode* rightnext=nullptr;
        while(left>0){
            left--;
            right--;
            preleft=leftnode;
            leftnode=leftnode->next;
            rightnode=rightnode->next;
        }
        while(right>0){
            right--;
            rightnode=rightnode->next;
        }
        rightnext=rightnode->next;
        rightnode->next=nullptr;
        ListNode* reversedhead=reverseLL(leftnode);
        if(preleft){
            preleft->next=reversedhead;
        }
        else{
            head=reversedhead;
        }
        leftnode->next=rightnext;
        return head;
    }
};