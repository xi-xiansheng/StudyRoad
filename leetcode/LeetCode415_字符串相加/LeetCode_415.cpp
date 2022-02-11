//法一
/*class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num2.size() > num1.size())
        {
            std::swap(num1,num2);
        }
        num1 = "0" + num1;
        std::string::reverse_iterator it1 = num1.rbegin();
        std::string::reverse_iterator it2 = num2.rbegin();
        string str = "";

        while(it2 != num2.rend())
        {
            *(it1 + 1) = *(it1 + 1) + (*it1 -'0' + *it2 - '0') / 10;
            str += (*it1 - '0' + *it2 - '0') % 10 + '0';
            it1++;
            it2++;
        }

        while(it1 != num1.rend() - 1)
        {

            *(it1 + 1) += *it1 / ('9' + 1);
            *it1 = (*it1 - '0') % 10 + '0';
            str += *it1;
            it1++;
        }
        if(*it1 != '0')
        {
            str += *it1;
        }
        std::reverse(str.begin(),str.end());
        return str;
    }
};*/

//法二

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        //flag用来标记是否进位
        int flag = 0;
        string str = "";
        while (i >= 0 || j >= 0)
        {
            int p1 = (i >= 0 ? num1[i--] - '0' : 0);
            int p2 = (j >= 0 ? num2[j--] - '0' : 0);
            str += '0' + (p1 + p2 + flag) % 10;
            flag = (p1 + p2 + flag) / 10;
        }
        if (flag)
        {
            str += '1';
        }

        std::reverse(str.begin(), str.end());
        return str;
    }
};
