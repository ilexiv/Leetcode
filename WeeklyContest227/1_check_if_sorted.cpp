#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
#endif

// Last and first elements are also connected, so we can iterate for 0 to n,
// and check last element with first by doing % of nums.size().
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[(i + 1) % nums.size()])
            {
                cnt++;
            }
            if (cnt > 1)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
}