class Solution {
public:
    int RunningTime(vector<int>& piles, int speed)
    {
        int time = 0;
        int sz = piles.size();
        for (int i = 0; i < sz; i++)
        {
            time += piles[i] / speed;
            if (piles[i] % speed)
                time++;
        }
        return time;
    }
    int BinarySearch(vector<int>& piles, int h, int left, int right)
    {
        int speed = (left + right) / 2;
        while (left < right)
        {
            speed = left + (right - left) / 2;
            int time = RunningTime(piles, speed);
            if (time > h)
                left = speed + 1;
            else
                right = speed;
        }
        return right;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = piles[0];
        for (int& e : piles)
        {
            if (e > right)
                right = e;
        }
        return BinarySearch(piles, h, left, right);
    }
};