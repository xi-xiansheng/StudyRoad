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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        int len = 0;
        ListNode* cur = head;
        while (cur)
        {
            cur = cur->next;
            len++;
        }
        k %= len;
        ListNode* prev = head;
        cur = head;
        while (k--)
        {
            cur = cur->next;
        }
        while (cur->next)
        {
            cur = cur->next;
            prev = prev->next;
        }
        cur->next = head;
        head = prev->next;
        prev->next = nullptr;
        return head;
    }
};