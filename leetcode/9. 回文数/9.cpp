/*class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<int> vc;
        while(x / 10)
        {
            vc.push_back(x % 10);
            x /= 10;
        }
        vc.push_back(x);
        int left = 0;
        int right = vc.size() - 1;
        while(left < right)
        {
            if(vc[left] != vc[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int y = 0;
        while (y < x)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return x == y || x == y / 10;
    }
};