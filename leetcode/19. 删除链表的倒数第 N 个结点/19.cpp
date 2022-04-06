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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* last = head;
        ListNode* parent = nullptr;
        while (n && first)
        {
            first = first->next;
            n--;
        }
        if (n)
        {
            return head;
        }
        while (first)
        {
            first = first->next;
            parent = last;
            last = last->next;
        }
        if (parent == nullptr)
        {
            return head->next;
        }
        else
        {
            parent->next = last->next;
        }
        return head;
    }
};