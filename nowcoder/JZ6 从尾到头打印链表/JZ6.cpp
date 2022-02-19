/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        //方法一:逆序
        vector<int> ve;
        while (head != nullptr)
        {
            ve.push_back(head->val);
            head = head->next;
        }
        std::reverse(ve.begin(), ve.end());
        return ve;
        //方法二：递归
        //方法三：栈
        /*stack<int> st;
        vector<int> ve;
        while(head != nullptr)
        {
            st.push(head->val);
            head = head -> next;
        }
        while(!st.empty())
        {
            ve.push_back(st.top());
            st.pop();
        }
        return ve;*/
    }
};