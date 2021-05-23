#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <numeric>
#include <queue>

using namespace std;

#if 0
https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
#endif

// ceil: (a + b - 1) / b;
class Solution {
public:
    double hours(vector<int>& dist, int speed) {
        double time = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            int t = dist[i] / speed;
            if (dist[i] % speed != 0) t++;
            time += t;
            //time += ((dist[i] + speed - 1) / speed);
        }
        time += double(dist.back()) / speed;
        return time;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour < dist.size() - 1) return -1;
        int left = 1;
        int right = 10000007;
        while (left < right) {
            int mid = left + (right - left) / 2;
            double time = hours(dist, mid);
            if (time <= hour) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left == 10000007 ? -1 : left;
    }
};

int main()
{
}