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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr)
            return head;
        int index = 1;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* newhead = nullptr;
        ListNode* newtail = nullptr;
        while (cur && index < left)
        {
            prev = cur;
            cur = cur->next;
            index++;
        }
        if (cur == nullptr)
            return head;
        newhead = newtail = cur;
        cur = cur->next;
        index++;
        while (cur && index <= right)
        {
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = newhead;
            newhead = tmp;
            index++;
        }
        newtail->next = cur;
        if (prev)
            prev->next = newhead;
        else
            head = newhead;
        return head;
    }
};