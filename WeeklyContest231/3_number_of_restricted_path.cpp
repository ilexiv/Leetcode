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
https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
#endif

class Solution
{
public:
    using ip = pair<int, int>;
    const int mod = 1e9 + 7;

    int dfs(vector<vector<ip>> &adj, vector<int> &dist, int start, vector<int> &dp)
    {
        if (start == 1)
        {
            return 1;
        }

        if (dp[start] != -1)
        {
            return dp[start];
        }
        int count = 0;

        for (auto &[next, _] : adj[start])
        {
            if (dist[next] > dist[start])
            {
                count = (count + dfs(adj, dist, next, dp)) % mod;
            }
        }

        dp[start] = count;

        return dp[start];
    }

    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        vector<vector<ip>> adj(n + 1, vector<ip>{});

        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<ip, vector<ip>, greater<ip>> pq;
        vector<int> dist(n + 1, INT_MAX);

        pq.push({0, n});
        dist[n] = 0;

        while (!pq.empty())
        {
            auto [_, node] = pq.top();
            pq.pop();

            for (auto &[next, w] : adj[node])
            {
                if (dist[next] > dist[node] + w)
                {
                    dist[next] = dist[node] + w;
                    pq.push({dist[next], next});
                }
            }
        }

        vector<int> dp(n + 1, -1);

        return dfs(adj, dist, n, dp);
    }
};

int main()
{
}