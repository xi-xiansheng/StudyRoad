class Solution {
public:
    pair<string, int> getdiff(int number)
    {
        if (number == 0)
            return make_pair("", 0);
        if (number > 999)
        {
            return make_pair("M", number - 1000);
        }
        /*if(number == 999)
        {
            return make_pair("IM", number - 999);
        }
        if(number == 995)
        {
            return make_pair("VM", number - 995);
        }
        if(number == 990)
        {
            return make_pair("XM", number - 990);
        }*/
        if (number >= 900)
        {
            return make_pair("CM", number - 900);
        }
        if (number > 499)
        {
            return make_pair("D", number - 500);
        }
        /*if(number == 499)
        {
            "CDXCIX"
            return make_pair("ID", number - 499);
        }
        if(number == 495)
        {

            return make_pair("VD", number - 495);
        }
        if(number == 490)
        {
            return make_pair("XD", number - 490);
        }*/
        if (number >= 400)
        {
            return make_pair("CD", number - 400);
        }
        if (number > 99)
        {
            return make_pair("C", number - 100);
        }
        /*if(number == 99)
        {
            return make_pair("IC", number - 99);
        }
        if(number == 95)
        {
            "XCV"
            return make_pair("VC", number - 95);
        }
        */
        if (number >= 90)
        {
            return make_pair("XC", number - 90);
        }
        if (number > 49)
        {
            return make_pair("L", number - 50);
        }
        /*if(number == 49)
        {
            //"XLIX" 49
            return make_pair("IL", number - 49);
        }*/
        /*if(number == 45)
        {
            //45 "XLV"
            return make_pair("VL", number - 45);
        }*/
        if (number >= 40)
        {
            return make_pair("XL", number - 40);
        }
        if (number > 9)
        {
            return make_pair("X", number - 10);
        }
        if (number == 9)
        {
            return make_pair("IX", number - 9);
        }
        if (number > 4)
        {
            return make_pair("V", number - 5);
        }
        if (number == 4)
        {
            return make_pair("IV", number - 4);
        }
        return make_pair("I", number - 1);
    }
    string intToRoman(int num) {
        string s;
        while (num)
        {
            pair<string, int> tmp = getdiff(num);
            s += tmp.first;
            num = tmp.second;
        }
        return s;
    }
};