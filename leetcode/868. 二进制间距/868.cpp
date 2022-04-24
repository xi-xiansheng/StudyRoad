class Solution {
public:
    int binaryGap(int n) {
        /*vector<int> vc;
        int index = 0;
        while(index < 32)
        {
            if((1 << index) & n)
            {
                vc.push_back(index);
            }
            index++;
        }
        int max = 0;
        for(int i = 0; i < index; i++)
        {
            if(i + 1 >= vc.size())
            {
                break;
            }
            if(vc[i + 1] - vc[i] > max)
            {
                max = vc[i + 1] - vc[i];
            }
        }
        return max;*/
        int ans = 0;
        for (int i = 0, j = -1; i < 32; i++)
        {
            if ((1 << i) & n)
            {
                if (j != -1)
                {
                    if (i - j > ans)
                    {
                        ans = i - j;
                    }
                }
                j = i;
            }
        }
        return ans;
    }
};