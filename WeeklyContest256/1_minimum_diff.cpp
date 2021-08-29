#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#if 0
https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
#endif

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i <= nums.size() - k; i++) {
            res = min(res, nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};

int main()
{
}