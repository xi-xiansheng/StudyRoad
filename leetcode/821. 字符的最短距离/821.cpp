class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        /*vector<int> vc;
        int sz = s.size();
        vc.resize(sz);
        //两边探测
        for(int index = 0; index < sz; index++)
        {
            int left = index;
            int right = index;

            while(true)
            {
                if(left >= 0 && s[left] == c)
                {
                    vc[index] = index - left;
                    break;
                }
                if(right < sz && s[right] == c)
                {
                    vc[index] = right - index;
                    break;
                }
                left--;
                right++;
            }

        }
        return vc;*/
        //时间优化
        vector<int> vc;
        queue<int> q;
        int sz = s.size();
        vc.resize(sz);
        for (int index = 0; index < sz; index++)
        {
            if (s[index] == c)
            {
                q.push(index);
            }
        }
        int index = 0;
        int first = q.front();
        q.pop();
        int last = first;
        while (index < sz)
        {
            first = last;
            if (q.empty())
            {
                last = -1;
            }
            else
            {
                last = q.front();
                q.pop();
            }
            if (index <= first)
            {
                while (index <= first)
                {
                    vc[index] = first - index;
                    index++;
                }
            }
            if (last == -1)
            {
                while (index < sz)
                {
                    vc[index] = index - first;
                    index++;
                }
                break;
            }
            else
            {
                while (index <= last)
                {
                    int min = (index - first) < (last - index) ? (index - first) : (last - index);
                    vc[index] = min;
                    index++;
                }
            }
        }
        return vc;
    }
};