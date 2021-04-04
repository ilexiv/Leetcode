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
https://leetcode.com/problems/finding-the-users-active-minutes/
#endif

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        unordered_map<int, unordered_set<int>> hmap;
        for (auto &l : logs)
            hmap[l[0]].insert(l[1]);
        vector<int> res(k, 0);
        for (auto &[_, ins] : hmap)
        {
            if (ins.size() <= k)
            {
                res[ins.size() - 1]++;
            }
        }
        return res;
    }
};

int main()
{
}