class Solution
{
public:
    string s = "";
    char count[256] = { 0 };
    //Insert one char from stringstream
    void Insert(char ch) {
        s += ch;
        count[ch] += 1;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (auto e : s)
        {
            if (count[e] == 1)
                return e;
        }
        return '#';
    }
};