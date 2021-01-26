#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/missing-element-in-sorted-array/
int missingElement(std::vector<int> &nums, int k)
{
    int size = nums.size() - 1;

    auto count = [&](int n) {
        return nums[n] - nums[0] - n;
    };

    if (k > count(size))
    {
        return nums[size] + k - count(size);
    }

    int l = 0;
    int r = nums.size();

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (count(mid) < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    return nums[r - 1] + k - count(r - 1);
}

int main()
{
    return 0;
}