/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr)
            return nullptr;
        RandomListNode* cur = pHead;
        //每个节点后，链接拷贝节点
        RandomListNode* copy = nullptr;
        while (cur)
        {
            copy = new RandomListNode(cur->label);
            RandomListNode* next = cur->next;
            cur->next = copy;
            copy->next = next;
            cur = next;
        }
        //置random
        cur = pHead;
        while (cur)
        {
            copy = cur->next;
            if (cur->random)
                copy->random = cur->random->next;
            else
                copy->random = nullptr;
            cur = copy->next;
        }

        //解链
        cur = pHead;
        RandomListNode* newhead = cur->next;
        while (cur)
        {
            RandomListNode* next = cur->next->next;
            copy = cur->next;
            cur->next = copy->next;
            if (next)
                copy->next = next->next;
            cur = next;
        }

        return newhead;
    }
};