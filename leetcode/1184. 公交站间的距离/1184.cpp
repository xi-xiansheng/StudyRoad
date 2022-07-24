class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int ans1 = 0, ans2 = 0;
        int begin = start;
        int end = destination;
        int sz = distance.size();
        while (begin != end)
        {
            ans1 += distance[begin];
            begin = (begin + 1) % sz;
        }
        begin = destination; end = start;
        while (begin != end)
        {
            ans2 += distance[begin];
            begin = (begin + 1) % sz;
        }
        return ans1 < ans2 ? ans1 : ans2;
    }
};