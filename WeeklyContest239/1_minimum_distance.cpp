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
https://leetcode.com/problems/minimum-distance-to-the-target-element/
#endif

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};

int main()
{
}