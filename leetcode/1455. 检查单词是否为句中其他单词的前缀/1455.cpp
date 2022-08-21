class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int _sz = searchWord.size();
        int ans = 0;
        for (int i = 0, sz = sentence.size(); i < sz; i++)
        {
            int start = i;
            ans++;
            while (i < sz && sentence[i] != ' ')
            {
                i++;
            }
            if (i - start < _sz)
                continue;
            string cmp(sentence.begin() + start, sentence.begin() + start + _sz);
            if (cmp == searchWord)
            {
                return ans;
            }
        }
        return -1;
    }
};