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
https://leetcode.com/problems/find-center-of-star-graph/
#endif

// A center node must appear in every edge.
class Solution2
{
public:
    int findCenter(vector<vector<int>> &e)
    {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        vector<int> adj(edges.size() + 2, 0);

        for (auto &e : edges)
        {
            adj[e[0]]++;
            adj[e[1]]++;
        }

        for (int i = 1; i < adj.size(); i++)
        {
            if (adj[i] > 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
}