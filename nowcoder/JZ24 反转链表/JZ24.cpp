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
    ListNode* ReverseList(ListNode* pHead) {
        //方法一：三指针
        if(pHead == nullptr)
            return nullptr;
        ListNode* cur = pHead;
        ListNode* next1 = cur ->next;
        ListNode* next2 = nullptr;
        while(next1)
        {
            next2 = next1 ->next;
            next1 -> next = cur;
            cur = next1;
            next1 = next2;
        }
        pHead ->next = nullptr;
        return cur;
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //方法二：头插法
        //创建新链表，pHead用以记录旧链表，newhead指向新链表头节点
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* newhead = nullptr;
        while (pHead)
        {
            //去掉旧链表头节点
            ListNode* tmp = pHead;
            pHead = pHead->next;
            //更新 新链表头结点
            tmp->next = newhead;
            newhead = tmp;
        }
        pHead = newhead;
        return pHead;
    }
};