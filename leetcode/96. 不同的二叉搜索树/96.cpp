class Solution {
public:
    int numTrees(int n) {
        vector<int> vc(n + 1, 0);
        vc[0] = 1;
        for (int index = 1; index <= n; index++)
        {
            int left = 0;
            int right = 0;
            for (int i = 1; i <= index; i++)
            {
                left = i - 1;
                right = index - i;
                vc[index] += vc[left] * vc[right];
            }
        }
        return vc[n];
    }
};