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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = head;
        ListNode* sub = head->next;
        while (sub && sub->next)
        {
            prev = prev->next;
            sub = sub->next->next;
        }
        ListNode* right = sortList(prev->next);
        prev->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* newhead = new ListNode();
        ListNode* tail = newhead;
        while (left && right)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left)
            tail->next = left;
        else
            tail->next = right;
        head = newhead->next;
        delete newhead;
        return head;
    }
};
/*class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* ret =  head;
        while(ret != nullptr)
        {
            v.push_back(ret->val);
            ret = ret->next;
        }
        std::sort(v.begin(), v.end());
        ret =  head;
        for(int i = 0, sz = v.size(); i < sz; i++){
            ret->val = v[i];
            ret = ret->next;
        }
        return head;
    }
};*/