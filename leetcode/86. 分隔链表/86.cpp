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
    ListNode* partition(ListNode* head, int x) {
        ListNode* mini = nullptr;
        ListNode* minitail = nullptr;
        ListNode* biger = nullptr;
        ListNode* bigertail = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                if (minitail == nullptr)
                    mini = minitail = cur;
                else
                {
                    minitail->next = cur;
                    minitail = minitail->next;
                }
            }
            else
            {
                if (bigertail == nullptr)
                    biger = bigertail = cur;
                else
                {
                    bigertail->next = cur;
                    bigertail = bigertail->next;
                }
            }
            cur = cur->next;
        }
        if (minitail)
            minitail->next = biger;
        else
            return head;
        if (bigertail)
            bigertail->next = nullptr;
        return mini;
    }
};