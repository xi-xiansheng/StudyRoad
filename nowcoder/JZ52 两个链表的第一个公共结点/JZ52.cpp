/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        int count1 = 0;
        int count2 = 0;
        ListNode* tmp = pHead1;
        while (tmp)
        {
            tmp = tmp->next;
            count1++;
        }
        tmp = pHead2;
        while (tmp)
        {
            tmp = tmp->next;
            count2++;
        }
        if (count1 > count2)
        {
            int length = count1 - count2;
            while (length--)
            {
                pHead1 = pHead1->next;
            }
        }
        else
        {
            int length = count2 - count1;
            while (length--)
            {
                pHead2 = pHead2->next;
            }
        }
        while (pHead1 != pHead2)
        {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead2;
    }
};