class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)
            return false;
        int index = sequence.size() - 1;
        int root_val = sequence[index--];
        vector<int> v_right;
        vector<int> v_left;
        stack<int> tmp;
        //ÓÒ×ÓÊ÷
        while (index >= 0 && sequence[index] > root_val)
        {
            tmp.push(sequence[index--]);
        }
        while (!tmp.empty())
        {
            v_right.push_back(tmp.top());
            tmp.pop();
        }
        //×ó×ÓÊ÷
        while (index >= 0 && sequence[index] < root_val)
        {
            tmp.push(sequence[index--]);
        }
        while (!tmp.empty())
        {
            v_left.push_back(tmp.top());
            tmp.pop();
        }


        if (index >= 0)
            return false;
        if (v_left.size() == 0 && v_right.size() == 0)
            return true;
        if (v_left.size() == 0)
            return VerifySquenceOfBST(v_right);
        if (v_right.size() == 0)
            return VerifySquenceOfBST(v_left);
        return VerifySquenceOfBST(v_right) && VerifySquenceOfBST(v_left);
    }
};