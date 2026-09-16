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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> st;
        int n=lists.size();
        if(n==0){
            return nullptr;
        }
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            if(temp==nullptr){
                continue;
            }
            while(temp!=nullptr){
                st.push_back(temp->val);
                temp=temp->next;
            }
        }
        if(st.size()==0){
            return nullptr;
        }
        sort(st.begin(),st.end());
        ListNode* head=new ListNode(st[0]);
        ListNode* mover=head;
        for(int i=1;i<st.size();i++){
            ListNode* newnode=new ListNode(st[i]);
            mover->next=newnode;
            mover=mover->next;
        }
        return head;
    }
};