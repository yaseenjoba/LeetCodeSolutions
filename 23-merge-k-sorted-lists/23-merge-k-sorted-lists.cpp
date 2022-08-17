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
    struct valueCompare {
        bool operator()(const ListNode *x, const ListNode *y) { return x->val > y->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *resultHead = nullptr;
        priority_queue<ListNode *, vector<ListNode *>, valueCompare> pq;
        for(auto i : lists){
          if(i == nullptr)continue;
          pq.push(i);
        }
        ListNode * temp = nullptr;
        while(!pq.empty()){
            ListNode *node = pq.top();
            pq.pop();
            if(resultHead == nullptr){
              resultHead = temp = node;
            }else{
              temp->next = node;
              temp = temp->next;
            }
            if(node->next != nullptr){
              pq.push(node->next);
            }
        }
        return resultHead;
    }
};