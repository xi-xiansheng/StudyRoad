class Solution {
public:

    string StringSort(const vector<string>& words, int MaxWidth)
    {
        string s;
        int count = 0;
        int len = 0;
        for (const auto e : words)
        {
            count++;
            len += e.size();
        }
        if (count == 1)
        {
            s += words[0];
            for (int i = 0; i < MaxWidth - len; i++)
                s += ' ';
            return s;
        }
        int countspace = (MaxWidth - len) / (count - 1);
        int mod = (MaxWidth - len) % (count - 1);
        for (const auto e : words)
        {
            s += e;
            for (int i = 0; i < countspace && count > 1; i++)
                s += ' ';
            if (mod)
            {
                s += ' ';
                mod--;
            }
            count--;
        }
        return s;
    }

    //左对齐
    string LeftJustify(const vector<string>& words, int MaxWidth)
    {
        string s;
        int count = 0;
        int len = 0;
        for (const auto e : words)
        {
            count++;
            len += e.size();
        }
        int surplus = MaxWidth - len;
        for (const auto e : words)
        {
            s += e;
            if (surplus)
            {
                s += ' ';
                surplus--;
            }
        }
        while (surplus--)
            s += ' ';
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vs;
        vector<string> record;
        int sz = words.size();
        int _sz = 0;
        for (int i = 0; i < sz; i++)
        {
            _sz = 0;
            record.resize(0);
            while (i < sz)
            {
                if (_sz + words[i].size() <= maxWidth)
                {
                    record.push_back(words[i]);
                    _sz += words[i].size();
                    _sz++;
                    i++;
                }
                else
                {
                    i--;
                    break;
                }
            }
            vs.push_back(StringSort(record, maxWidth));
        }
        //最后一个左对齐
        vs[vs.size() - 1] = LeftJustify(record, maxWidth);
        return vs;
    }
};