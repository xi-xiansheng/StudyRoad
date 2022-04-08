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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* prev = head->next;
        ListNode* last = head;
        ListNode* tail = nullptr;
        if (prev)
        {
            head = prev;
        }
        while (prev && last)
        {
            last->next = prev->next;
            prev->next = last;
            if (tail == nullptr)
            {
                tail = last;
            }
            else
            {
                tail->next = prev;
                tail = last;
            }
            last = last->next;
            if (last)
            {
                prev = last->next;
            }
            else
            {
                break;
            }
        }
        return head;
    }
};