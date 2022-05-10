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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* cur = head;
        while (cur && cur->next)
        {
            ListNode* tmp = cur;
            while (tmp->next && tmp->val == tmp->next->val)
            {
                tmp = tmp->next;
            }
            cur->next = tmp->next;
            cur = cur->next;
        }
        return head;
    }
};