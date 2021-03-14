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
https://leetcode.com/problems/closest-dessert-cost/
#endif

class Solution
{
public:
    int ans = -1;

    void dfs(int cost, int pos, vector<int> &topping, int target)
    {
        if (cost >= target || pos == topping.size())
        {
            // If the answer is not yet calculated or it is closer than previous,
            // or it is less than previous calculated -> update the result.
            // We can get rid of ans check by inititalizing it to INT_MAX.
            if (ans == -1 || abs(cost - target) < abs(ans - target) ||
                (abs(cost - target) == abs(ans - target) && cost < ans))
            {
                ans = cost;
            }
            return;
        }

        dfs(cost, pos + 1, topping, target);
        dfs(cost + topping[pos], pos + 1, topping, target);
        dfs(cost + 2 * topping[pos], pos + 1, topping, target);
    }

    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        for (int i = 0; i < baseCosts.size(); i++)
        {
            dfs(baseCosts[i], 0, toppingCosts, target);
        }
        return ans;
    }
};

int main()
{
}