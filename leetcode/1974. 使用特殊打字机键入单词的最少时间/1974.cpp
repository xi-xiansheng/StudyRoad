class Solution {
public:
    int minTimeToType(string word) {
        int step = 0;
        for (const char& ch : word)
        {
            int index = ch - 'a';
            step += std::min(abs(_index - index), std::min(index + 26 - _index, _index + 26 - index));
            step += 1;
            _index = index;
        }
        return step;
    }
private:
    int _index = 0;
};