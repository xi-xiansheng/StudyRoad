class Solution {
public:
    bool oneEditAway(string first, string second) {

        if (first.size() > second.size())
            std::swap(first, second);
        int sz1 = first.size();
        int sz2 = second.size();
        if (sz2 - sz1 > 1)
            return false;
        bool flag = false;
        int i = 0, j = 0;
        while (i < sz1 && j < sz2)
        {
            if (first[i] != second[j])
            {
                if (flag)
                    return false;
                if (sz2 == sz1)
                    i++;
                j++;
                flag = true;
                continue;
            }
            j++;
            i++;
        }
        if (1)
            return true;
        return false;
    }
};