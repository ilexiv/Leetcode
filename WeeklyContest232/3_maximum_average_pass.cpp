#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <numeric>

using namespace std;

#if 0
https://leetcode.com/problems/maximum-average-pass-ratio/
#endif

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, array<int, 2>>> pq;
        double total = 0;

        auto profit = [](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };

        for (auto &c : classes)
        {
            total += (double)c[0] / c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents)
        {
            auto [extra, p] = pq.top();
            pq.pop();
            total += extra;
            extraStudents--;
            pq.push({profit(p[0] + 1, p[1] + 1), {p[0] + 1, p[1] + 1}});
        }

        return total / classes.size();
    }
};

int main()
{
}