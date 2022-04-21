class Solution {
public:

    bool IsVowel(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 'a' - 'A';
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

    int CountTokens(const string& sentence)
    {
        int count = 0;
        for (auto e : sentence)
        {
            if (e == ' ')
            {
                count++;
            }
        }
        return count + 1;
    }

    string toGoatLatin(string sentence) {
        int count = CountTokens(sentence);
        int sz = sentence.size();
        string newsentence;
        newsentence.resize(sentence.size() + 2 * count + (count + 1) * count / 2);
        for (int index = 1, i = 0, j = 0; i < sz; i++)
        {
            if (IsVowel(sentence[i]))
            {
                while (i < sz && sentence[i] != ' ')
                {
                    newsentence[j++] = sentence[i++];
                }
                newsentence[j++] = 'm';
                newsentence[j++] = 'a';
            }
            else
            {
                char tmp = sentence[i++];
                while (i < sz && sentence[i] != ' ')
                {
                    newsentence[j++] = sentence[i++];
                }
                newsentence[j++] = tmp;
                newsentence[j++] = 'm';
                newsentence[j++] = 'a';
            }
            if (sentence[i] == ' ')
            {
                for (int space = 0; space < index; space++)
                {
                    newsentence[j++] = 'a';
                }
                newsentence[j++] = ' ';
                index++;
            }
        }
        sz = newsentence.size() - 1;
        while (count)
        {
            newsentence[sz--] = 'a';
            count--;
        }
        return newsentence;
    }
};