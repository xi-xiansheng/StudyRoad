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
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr)
            return nullptr;
        ListNode* newhead = nullptr;
        ListNode* tailprev = pHead;

        while (pHead)
        {
            //找到头结点
            ListNode* cur = pHead;
            while (cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            if (cur == pHead)
            {
                newhead = pHead;
                tailprev = cur;
                break;
            }
            else
            {
                pHead = cur->next;
                continue;
            }
        }
        if (pHead)
            pHead = pHead->next;
        while (pHead)
        {
            //尾巴
            ListNode* cur = pHead;
            while (cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            if (cur == pHead)
            {
                tailprev->next = cur;
                tailprev = cur;
                pHead = pHead->next;
            }
            else
            {
                pHead = cur->next;
            }
        }
        if (tailprev)
            tailprev->next = nullptr;
        return newhead;
    }
};