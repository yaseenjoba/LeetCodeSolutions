/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode * , int>mm;
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=NULL && b!=NULL){
            mm[a]++;
            a = a->next;
        }
         while(b!=NULL){
            mm[b]++;
            b = b->next;
        }
        for(auto i : mm){
            if(i.second == 2){
                return i.first;    
            }
        }
        return NULL;
    }
};