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

using namespace std;

#if 0
https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/
#endif

class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long int sum = accumulate(nums.begin(), nums.end(), 0L);
        sum = abs(goal - sum);

        return (sum + limit - 1) / limit;
    }
};

class Solution1
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long int sum = accumulate(nums.begin(), nums.end(), 0L);
        long long int cnt = 0;

        sum = abs(goal - sum);

        while (sum > 0)
        {
            if (sum / limit > 0)
            {
                cnt += sum / limit;
                sum = sum % limit;
            }
            else
            {
                cnt++;
                sum -= limit;
            }
        }

        return cnt;
    }
};

int main()
{
}