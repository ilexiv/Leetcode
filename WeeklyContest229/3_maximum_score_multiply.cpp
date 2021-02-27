#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

#if 0
https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
#endif

class Solution
{
public:
    vector<int> nums1;
    vector<int> mul1;
    int dp[1001][1001] = {0};
    int dfs(int nl, int nr, int ind)
    {
        if (ind >= mul1.size())
        {
            return 0;
        }

        if (dp[nl][ind])
        {
            return dp[nl][ind];
        }

        dp[nl][ind] = max(nums1[nl] * mul1[ind] + dfs(nl + 1, nr, ind + 1),
                          nums1[nr] * mul1[ind] + dfs(nl, nr - 1, ind + 1));

        return dp[nl][ind];
    }

    int maximumScore(vector<int> &nums, vector<int> &mul)
    {
        nums1 = nums;
        mul1 = mul;
        return dfs(0, nums.size() - 1, 0);
    }
};

int main()
{
}