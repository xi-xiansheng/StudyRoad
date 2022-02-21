/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here

        //前后指针法
        ListNode* cur = pHead;
        ListNode* pos = pHead;
        while (k && cur)
        {
            cur = cur->next;
            k--;
        }
        if (cur == nullptr && k != 0)
            return cur;
        while (cur)
        {
            cur = cur->next;
            pos = pos->next;
        }
        return pos;
    }
};