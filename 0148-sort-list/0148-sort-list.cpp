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
    ListNode* mergeList(ListNode* list1,ListNode* list2){
        if(list1==nullptr && list2==nullptr){
            return nullptr;
        }
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* mover=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                mover->next=list1;
                list1=list1->next;
            }
            else{
                mover->next=list2;
                list2=list2->next;
            }
            mover=mover->next;
        }
        if(list1!=nullptr){
            mover->next=list1;
        }
        else{
            mover->next=list2;
        }
        mover=dummy->next;
        delete(dummy);
        return mover;
    }
    ListNode* findmiddlenode(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* middle=findmiddlenode(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=nullptr;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return mergeList(lefthead,righthead);
    }
};