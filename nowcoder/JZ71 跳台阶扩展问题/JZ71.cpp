class Solution {
public:
    int jumpFloorII(int number) {
        //Ë¼Â·£ºFn = 2 ^ (n - 1)
        return pow(2, number - 1);
    }
};