/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
/*class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        //方法一
        if(pHead1 == nullptr)
            return pHead2;
        if(pHead2 == nullptr)
            return pHead1;
        ListNode* new_head = nullptr;
        ListNode *new_tail = nullptr;
        while(pHead1 && pHead2)
        {
            //尾插
            ListNode* tmp = pHead1->val < pHead2->val ? pHead1 : pHead2;
            if(tmp == pHead1)
            {
                pHead1 = pHead1 ->next;
            }
            else
            {
                pHead2 = pHead2 ->next;
            }
            if(new_head == nullptr)
            {
                new_head = new_tail = tmp;
            }
            else
            {
                new_tail -> next = tmp;
                new_tail = new_tail -> next;
            }
        }
        if(pHead1 == nullptr)
        {
            new_tail ->next = pHead2;
        }
        else
        {
            new_tail ->next = pHead1;
        }
        return new_head;
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        //方法二：递归
        if (nullptr == pHead1)
        {
            return pHead2;
        }
        if (nullptr == pHead2)
        {
            return pHead1;
        }
        ListNode* newhead = pHead1->val < pHead2->val ? pHead1 : pHead2;
        if (newhead == pHead1)
        {
            pHead1 = pHead1->next;
        }
        else
        {
            pHead2 = pHead2->next;
        }
        newhead->next = Merge(pHead1, pHead2);
        return newhead;
    }
};