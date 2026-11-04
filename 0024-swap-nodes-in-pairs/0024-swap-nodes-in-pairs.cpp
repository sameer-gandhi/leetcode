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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* curr=head;
        ListNode* prenode=dummy;
        while(curr!=nullptr && curr->next!=nullptr){
            ListNode* first=curr;
            ListNode* second=first->next;
            ListNode* nextnode=second->next;

            first->next=second->next;
            second->next=first;
            prenode->next=second;

            curr=first->next;
            prenode=first;
        }
        curr=dummy->next;
        delete(dummy);
        return curr;
    }
};