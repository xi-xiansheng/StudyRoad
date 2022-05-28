class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int distance = 0x7fffffff;
        int pos1 = -1;
        int pos2 = -1;
        int sz = words.size();
        for (int i = 0; i < sz; i++)
        {
            if (words[i] == word1)
                pos1 = i;
            else if (words[i] == word2)
                pos2 = i;
            else
                continue;
            if (abs(pos1 - pos2) < distance && (pos1 != -1 && pos2 != -1))
                distance = abs(pos1 - pos2);
        }
        return distance;
    }
};