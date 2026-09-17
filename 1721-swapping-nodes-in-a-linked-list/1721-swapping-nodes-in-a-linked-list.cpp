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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        vector<int> arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        swap(arr[k-1],arr[n-k]);
        ListNode* newhead=new ListNode(arr[0]);
        ListNode* mover=newhead;
        for(int i=1;i<n;i++){
            ListNode* newnode=new ListNode(arr[i]);
            mover->next=newnode;
            mover=mover->next;
        }
        return newhead;
    }
};