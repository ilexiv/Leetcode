#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/maximum-ascending-subarray-sum/
#endif

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int res = 0, tmp = 0, prev = -1;
        for (auto &n : nums)
        {
            if (n <= prev)
                tmp = 0;
            tmp += n;
            prev = n;
            res = max(res, tmp);
        }
        return res;
    }
};

int main()
{
}