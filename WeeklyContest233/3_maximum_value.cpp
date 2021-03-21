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
#include <array>

using namespace std;

#if 0
https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
#endif

class Solution
{
public:
    // arithmetic progression, could be improved.
    bool check(int n, int i, int maxSum, int m)
    {
        for (int d = 1; maxSum >= 0 && d < m && i + d < n; ++d)
            maxSum -= m - d;
        for (int d = 1; maxSum >= 0 && d < m && i - d >= 0; ++d)
            maxSum -= m - d;
        return maxSum >= 0;
    }

    bool check1(int n, int i, long maxSum, long m)
    {
        int cnt_l = i, cnt_r = n - i - 1;
        long l_val = m * (m - 1) / 2 - max(0l, m - cnt_l - 1) * max(0l, m - cnt_l) / 2;
        long r_val = m * (m - 1) / 2 - max(0l, m - cnt_r - 1) * max(0l, m - cnt_r) / 2;
        return maxSum >= l_val + r_val;
    }

    int maxValue(int n, int index, int maxSum)
    {
        int left = 0, right = maxSum;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (check(n, index, maxSum - n - mid, mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
}