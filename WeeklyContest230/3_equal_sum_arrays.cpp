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

using namespace std;

#if 0
https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
#endif

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
            return -1;

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (sum1 > sum2)
        {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = nums2.size() - 1;
        int op = 0;

        while (sum2 > sum1)
        {
            op++;
            if (j < 0 || 6 - nums1[i] > nums2[j] - 1)
            {
                sum1 += 6 - nums1[i];
                i++;
            }
            else
            {
                sum2 -= nums2[j] - 1;
                j--;
            }
        }

        return op;
    }
};

class Solution1
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
            return -1;

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (sum1 > sum2)
        {
            swap(nums1, nums2);
        }

        priority_queue<int, vector<int>, greater<int>> pq1(nums1.begin(), nums1.end()); // min heap
        priority_queue<int> pq2(nums2.begin(), nums2.end());                            // max heap

        int cnt = 0;
        int op = 0;
        int diff = abs(sum1 - sum2);

        while (diff > 0)
        {
            op++;
            if (pq1.empty() || (!pq2.empty() && pq2.top() - 1 > 6 - pq1.top()))
            {
                diff -= (pq2.top() - 1);
                pq2.pop();
            }
            else
            {
                diff -= (6 - pq1.top());
                pq1.pop();
            }
        }

        return op;
    }
};

int main()
{
}