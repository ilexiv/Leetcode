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
https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
#endif

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long unsigned int maxel = *max_element(milestones.begin(), milestones.end());
        long long unsigned int sum = 0;
        for (auto& m : milestones) sum += m;
        if (sum - maxel >= maxel) return sum;
        return (sum - maxel) * 2 + 1;
    }
};

int main()
{
}