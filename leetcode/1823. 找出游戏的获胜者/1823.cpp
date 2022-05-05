/*class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vc(n, 1);
        int index = 0;
        int count = n;
        while(count > 1)
        {
            int tmp = k;
            while(tmp)
            {
                if(vc[index] == 1)
                {
                    if(tmp == 1)
                        vc[index] = 0;
                    tmp--;
                }
                index = (index + 1) % n;
            }
            count--;
        }
        index = 0;
        while(vc[index] == 0)
            index++;
        return index + 1;
    }
};*/

//利用约瑟夫问题的递推公式 f(n,m) = ( f(n-1,m) + m) % n )
class Solution {
public:
    int findTheWinner(int n, int k) {
        int fn = 0;
        int i = 2;
        while (i <= n)
        {
            fn = (fn + k) % i;
            i++;
        }
        return fn + 1;
    }
};