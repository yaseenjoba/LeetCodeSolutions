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
    ListNode* rotateRight(ListNode* head, int rotations) {
        if (head == nullptr || head->next == nullptr || rotations <= 0) {
          return head;
        }

        ListNode *lastNode = head;
        int listLength = 1;
        while (lastNode->next != nullptr) {
          lastNode = lastNode->next;
          listLength++;
        }

        lastNode->next = head;   
        rotations %= listLength; 
        int skipLength = listLength - rotations;
        ListNode *lastNodeOfRotatedList = head;
        for (int i = 0; i < skipLength - 1; i++) {
          lastNodeOfRotatedList = lastNodeOfRotatedList->next;
        }

        head = lastNodeOfRotatedList->next;
        lastNodeOfRotatedList->next = nullptr;
        return head;
    }
};