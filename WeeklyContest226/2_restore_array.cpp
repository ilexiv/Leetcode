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
https://leetcode.com/contest/weekly-contest-226/problems/restore-the-array-from-adjacent-pairs/
#endif

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &a)
    {
        unordered_map<int, vector<int>> hmap;

        for (auto &el : a)
        {
            hmap[el[0]].push_back(el[1]);
            hmap[el[1]].push_back(el[0]);
        }

        stack<int> s;
        for (auto &v : hmap)
        {
            if (v.second.size() == 1)
            {
                s.push(v.first);
                break;
            }
        }

        vector<int> res;
        unordered_set<int> vis;

        vis.insert(s.top());

        while (!s.empty())
        {
            int n = s.top();
            s.pop();

            res.push_back(n);

            for (auto &el : hmap[n])
            {
                if (!vis.count(el))
                {
                    vis.insert(el);
                    s.push(el);
                }
            }
        }

        return res;
    }
};

int main()
{
}