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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int number1 = 0;
        int number2 = 0;
        int flag = 0;
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        flag = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* tail = head;

        while (l1 || l2)
        {
            int tmp = flag;
            if (l1)
            {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                tmp += l2->val;
                l2 = l2->next;
            }
            flag = tmp / 10;
            tail->next = new ListNode(tmp % 10);
            tail = tail->next;
        }
        if (flag)
        {
            tail->next = new ListNode(flag);
        }
        return head;
    }
};