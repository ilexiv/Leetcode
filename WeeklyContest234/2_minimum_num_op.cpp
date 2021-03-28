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
https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
#endif

class Solution
{
public:
    int reinitializePermutation(int n)
    {
        vector<int> orig(n, 0);
        iota(orig.begin(), orig.end(), 0);
        vector<int> prev = orig;
        vector<int> temp(n, 0);
        int cnt = 0;
        while (temp != orig)
        {
            for (int i = 0; i < n; i++)
                temp[i] = (i % 2 == 0) ? prev[i / 2] : prev[n / 2 + (i - 1) / 2];
            prev = temp;
            cnt++;
        }
        return cnt;
    }
};

class Solution1
{
public:
    int reinitializePermutation(int n)
    {
        int res = 0;
        int i = 1;
        while (res == 0 || i > 1)
        {
            i = (i < n / 2) ? i * 2 : (i - n / 2) * 2 + 1;
            res++;
        }
        return res;
    }
};

int main()
{
}