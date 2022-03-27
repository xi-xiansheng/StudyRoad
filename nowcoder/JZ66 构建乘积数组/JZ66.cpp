class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> vc;
        vector<int> right;
        int size = A.size();
        vc.resize(size);
        right.resize(size);
        vc[0] = 1;
        for (int i = 1; i < size; i++)
        {
            //×ó
            vc[i] = vc[i - 1] * A[i - 1];
        }
        right[size - 1] = 1;
        for (int i = size - 2; i >= 0; i--)
        {
            //ÓÒ
            right[i] = right[i + 1] * A[i + 1];
        }
        //ÕûºÏ
        for (int i = 0; i < size; i++)
        {
            vc[i] *= right[i];
        }
        return vc;
    }
};