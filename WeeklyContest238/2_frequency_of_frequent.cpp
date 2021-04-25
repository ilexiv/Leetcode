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
https://leetcode.com/problems/frequency-of-the-most-frequent-element/
#endif

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long res = 0, sum = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (j < i && sum + k < nums[i] * (i - j + 1)) {
                sum -= nums[j++];
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

int main()
{
}