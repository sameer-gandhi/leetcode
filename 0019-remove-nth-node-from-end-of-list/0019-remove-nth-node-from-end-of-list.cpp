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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr || head==nullptr){
            return nullptr;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        int k=cnt-n+1;
        ListNode* pre=head;
        temp=head->next;
        cnt=1;
        while(temp!=nullptr){
            cnt++;
            if(cnt==k){
                pre->next=temp->next;
                delete(temp);
                break;
            }
            pre=temp;
            temp=temp->next;
        }
        return head;
    }
};