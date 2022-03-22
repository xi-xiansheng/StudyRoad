/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        //前后指针法
        if (pHead == nullptr)
            return nullptr;
        ListNode* _prev = pHead->next;
        ListNode* _next = pHead;
        while (_prev && _prev->next && _next != _prev)
        {
            _prev = _prev->next->next;
            _next = _next->next;
        }
        if (_prev == nullptr || _prev->next == nullptr)
            return nullptr;
        ListNode* _end = _next;

        _prev = pHead;
        _next = _end->next;

        int step_prev = 0;
        int step_next = 0;
        while (_prev != _end)
        {
            step_prev++;
            _prev = _prev->next;
        }
        while (_next != _end)
        {
            step_next++;
            _next = _next->next;
        }
        _prev = pHead;
        _next = _end->next;
        if (step_next > step_prev)
        {
            while (step_next > step_prev)
            {
                step_next--;
                _next = _next->next;
            }
        }
        else
        {
            while (step_prev > step_next)
            {
                step_prev--;
                _prev = _prev->next;
            }
        }

        while (_next != _prev)
        {
            _prev = _prev->next;
            _next = _next->next;
        }

        return _prev;

    }
};