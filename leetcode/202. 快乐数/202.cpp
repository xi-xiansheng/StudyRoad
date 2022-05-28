/*class Solution {
public:
    bool isHappy(int n) {
        int flag = n;
        set<int> dic;
        dic.insert(n);
        while(n != 1)
        {
            int newnumber = 0;
            while(n)
            {
                int res = n % 10;
                n /= 10;
                newnumber += (int)pow(res, 2);
            }
            if(dic.find(newnumber) != dic.end())
                return false;
            dic.insert(newnumber);
            n = newnumber;
        }
        return true;
    }
};*/
class Solution {
public:
    // ¿ìÂıÖ¸Õë·¨
    int HappyNumber(int n)
    {
        int newnumber = 0;
        while (n)
        {
            int res = n % 10;
            n /= 10;
            newnumber += (int)pow(res, 2);
        }
        return newnumber;
    }


    bool isHappy(int n) {
        int fast = HappyNumber(n);
        int slow = n;
        while (fast != slow)
        {
            fast = HappyNumber(HappyNumber(fast));
            slow = HappyNumber(slow);
        }
        return fast == 1;
    }
};