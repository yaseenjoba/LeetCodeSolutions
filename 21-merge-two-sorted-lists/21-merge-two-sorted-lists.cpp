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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int>res;
        while(l1!=NULL){
            res.push_back(l1->val);
            l1=l1->next;
        }
         while(l2!=NULL){
            res.push_back(l2->val);
            l2=l2->next;
        }
        if(res.size() == 0)return NULL;
        sort(res.begin() , res.end());
        ListNode* head = new ListNode(res[0]);
        ListNode* temp = head;
        for(int i = 1 ; i <res.size() ;i++){
            ListNode* t = new ListNode(res[i]);
            temp->next = t;
            temp = t;
        }
        return head;
        
    }
};