class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vc.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            vc[i] = i;
        }
        /*
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'D')
            {
                int max = i;
                for(int j = i; j < n + 1; j++)
                {
                    if(vc[max] < vc[j])
                        max = j;
                }
                std::swap(vc[i], vc[max]);
            }
            else
            {
                int min = i;
                for(int j = i; j < n + 1; j++)
                {
                    if(vc[min] > vc[j])
                        min = j;
                }
                std::swap(vc[i], vc[min]);
            }
        }*/
        int left = 0;
        int right = n;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                vc[i] = right--;
            else
                vc[i] = left++;
        }
        vc[n] = right;
        return vc;
    }
private:
    vector<int> vc;
};