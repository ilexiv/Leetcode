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
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/submissions/
#endif

// Appy binary serach to serach for a minimum possible size.
class Solution
{
public:
    int minimumSize(vector<int> &A, int k)
    {
        int left = 1, right = 1e9;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = 0;

            for (auto &a : A)
            {
                count += (a - 1) / mid;
            }

            if (count > k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

int main()
{
}