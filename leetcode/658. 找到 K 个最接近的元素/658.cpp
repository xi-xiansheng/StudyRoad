/*class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // ≈≈–Ú
        auto f = [&] (int a, int b)-> bool{
            int dif = abs(a - x) - abs(b - x);
            return  dif < 0 || (dif == 0 && a < b);};
        std::sort(arr.begin(), arr.end(), f);
        vector<int> ans(arr.begin(), arr.begin() + k);
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // ◊Û”“÷∏’Î
        int l = -1, r = -1, sz = arr.size();
        int left = 0, right = sz - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] < x)
            {
                l = mid;
                left = mid + 1;
            }
            else
            {
                r = mid;
                right = mid - 1;
            }
        }
        if (l != -1 && r != -1)
        {
            while (l >= 0 && r < sz && r - l <= k)
            {
                int dif = abs(arr[l] - x) - abs(arr[r] - x);
                if (dif <= 0)
                    l--;
                else
                    r++;
            }
        }
        if (l == -1)
            return vector<int>(arr.begin(), arr.begin() + k);
        else if (r == -1 || r >= sz)
            return vector<int>(arr.begin() + sz - k, arr.end());
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};