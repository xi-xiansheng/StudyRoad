class Solution {
public:
    bool isValidSerialization(string preorder) {
        int dif = 1;
        int sz = preorder.size();
        int cur = 0;
        while (cur < sz)
        {
            dif--;
            if (dif < 0)
                return false;
            int begin = cur;
            while (cur < sz && preorder[cur] != ',')
            {
                cur++;
            }
            string ret(preorder.begin() + begin, preorder.begin() + cur++);
            if (ret != "#")
                dif += 2;
        }
        return dif == 0;
    }
};