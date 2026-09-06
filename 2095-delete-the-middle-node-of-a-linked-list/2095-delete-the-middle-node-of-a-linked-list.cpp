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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            temp=temp->next;
            cnt++;
        }
        int middle=cnt/2;
        if(middle==0){
            return head->next;
        }
        temp=head->next;
        cnt=1;
        ListNode* pre=head;
        while(temp!=nullptr){
            if(cnt==middle){
                pre->next=temp->next;
                break;
            }
            pre=temp;
            temp=temp->next;
            cnt++;
        }
        return head;
    }
};