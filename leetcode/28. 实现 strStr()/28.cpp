class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        while (haystack[i])
        {
            if (needle[j] == 0)
            {
                int iback = i - 1;
                int jback = j - 1;
                while (jback >= 0)
                {
                    if (haystack[iback] != needle[jback])
                    {
                        break;
                    }
                    jback--;
                    iback--;
                }
                if (jback == -1)
                {
                    return i - j;
                }
                else
                {
                    j--;
                    continue;
                }
            }

            if (haystack[i] == needle[j])
            {
                j++;
            }

            i++;
        }

        if (haystack[i] == 0 && needle[j] == 0)
        {
            int iback = i - 1;
            int jback = j - 1;
            while (iback >= 0 && jback >= 0)
            {
                if (haystack[iback] != needle[jback])
                {
                    break;
                }
                jback--;
                iback--;
            }
            if (jback == -1)
            {
                return i - j;
            }
            else
            {
                return -1;
            }
        }

        return -1;
    }
};