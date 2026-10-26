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
    ListNode* findkthnode(ListNode* head,int k){
        while(head!=nullptr && k>1){
            k--;
            head=head->next;
        }
        return head;
    }

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1){
            return head;
        }
        ListNode* temp=head;
        ListNode* prenode=nullptr;
        while(temp!=nullptr){
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==nullptr){
                if(prenode!=nullptr){
                    prenode->next=temp;
                }
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=nullptr;
            reverseLL(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prenode->next=kthnode;
            }
            prenode=temp;
            temp=nextnode;
        }
        return head;
    }
};