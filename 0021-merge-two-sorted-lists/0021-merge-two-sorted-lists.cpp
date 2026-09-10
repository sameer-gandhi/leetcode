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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        else if(list2==nullptr){
            return list1;
        }
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* head;
        if(temp1->val<temp2->val){
            head=new ListNode(temp1->val);
            temp1=temp1->next;
        }
        else{
            head=new ListNode(temp2->val);
            temp2=temp2->next;
        }
        ListNode* mover=head;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val<temp2->val){
                mover->next=new ListNode(temp1->val);
                mover=mover->next;
                temp1=temp1->next;
            }
            else{
                mover->next=new ListNode(temp2->val);
                mover=mover->next;
                temp2=temp2->next;
            }
        }
        while(temp1!=nullptr){
            mover->next=new ListNode(temp1->val);
            mover=mover->next;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            mover->next=new ListNode(temp2->val);
            mover=mover->next;
            temp2=temp2->next;
        }
        return head;
    }
};