class Solution {
public:
    static bool cmp(int x, int y)
    {
        string s1 = to_string(x);
        string s2 = to_string(y);
        return s1 + s2 < s2 + s1;
    }
    string PrintMinNumber(vector<int> numbers) {
        //ÅÅĞòË¼Ïë
        //if(numbers.size() == 0)
            //return "";
        size_t pos = 0;
        /*for(size_t i = 0; i < numbers.size() - 1; i++)
        {
            pos = 0;
            while(pos < numbers.size() - 1 - i)
            {
                if(!cmp(numbers[pos], numbers[pos + 1]))
                {
                    std::swap(numbers[pos], numbers[pos + 1]);
                }
                pos++;
            }
        }*/
        sort(numbers.begin(), numbers.end(), cmp);
        pos = 0;
        string s = "";
        while (pos < numbers.size())
        {
            s += to_string(numbers[pos]);
            pos++;
        }
        return s;
    }
};