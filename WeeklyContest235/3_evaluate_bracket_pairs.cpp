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
#include <set>

using namespace std;

#if 0
https://leetcode.com/problems/minimum-absolute-sum-difference/
#endif

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        set<int> s(a.begin(), a.end());
        int64_t m = 0;
        for (int i = 0; i < a.size(); i++)
            m +=  abs(a[i] - b[i]);
        int64_t ans = m;
        for (int i = 0; i < a.size(); i++) {
            auto it = s.lower_bound(b[i]);
            int t = abs(a[i] - b[i]);
            if (it != s.end())
                ans = min(ans, m - t + abs(*it - b[i]));
            if (it != s.begin()) {
                --it;
                ans = min(ans, m - t + abs(*it - b[i]));
            }
        }
        const int mod = 1e9 + 7;
        return ans % mod;
    }
};

int main()
{
}