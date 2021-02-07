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

using namespace std;

#if 0
https://leetcode.com/problems/maximum-score-from-removing-stones/
#endif

// Push the elements into pq and always get two max elements froom it,
// reduce by one and push back to pq. Continue while only only one element
// is not empty in pq.
class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int> pq;

        pq.push(a);
        pq.push(b);
        pq.push(c);

        int cnt = 0;
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            b--;
            a--;
            cnt++;

            if (a != 0)
                pq.push(a);
            if (b != 0)
                pq.push(b);
        }

        return cnt;
    }
};

// If the largest element is greater than sum of two others => the two other elements 
// will become equal to zero first => sum of two other elements is the anser.
// Otherwise, 
class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());

        if (nums[2] >= nums[0] + nums[1])
        {
            return nums[0] + nums[1];
        }

        return (nums[2] + nums[1] + nums[0]) / 2;
    }
};

int main()
{
}