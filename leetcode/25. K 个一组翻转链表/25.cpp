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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead = nullptr;
        ListNode* newtail = nullptr;
        ListNode* cur = head;
        int i = 1;
        while (cur)
        {
            ListNode* _tail = nullptr;
            ListNode* _head = nullptr;
            while (cur && (i % (k + 1)))
            {
                ListNode* tmp = cur->next;
                if (_head == nullptr)
                {
                    _head = _tail = cur;
                }
                else
                {
                    cur->next = _head;
                    _head = cur;
                }
                cur = tmp;
                i++;
            }
            if ((i % (k + 1)) && cur == nullptr)
            {
                cur = _head;
                _tail->next = nullptr;
                _tail = nullptr;
                _head = nullptr;
                while (cur)
                {
                    ListNode* tmp = cur->next;
                    if (_head == nullptr)
                    {
                        _head = _tail = cur;
                    }
                    else
                    {
                        cur->next = _head;
                        _head = cur;
                    }
                    cur = tmp;
                }
            }
            i++;
            if (newhead == nullptr)
            {
                newhead = _head;
                newtail = _tail;
                //newtail->next = nullptr;
                //[3,9,6,1,1,4,7]~4
            }
            else
            {
                newtail->next = _head;
                newtail = _tail;
            }
        }
        if (newtail)
        {
            newtail->next = nullptr;
        }
        return newhead;
    }
};