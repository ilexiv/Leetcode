#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <numeric>

using namespace std;

#if 0
https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
#endif

// Solution with TLE
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, int ind, vector<int> &visited, vector<int> &found)
    {
        found.push_back(ind);
        visited[ind] = 1;

        for (auto &a : adj[ind])
        {
            if (visited[a] == 0)
            {
                dfs(adj, a, visited, found);
            }
        }
    }

    unordered_map<int, int> check(vector<int> &source, vector<int> &fnd)
    {
        unordered_map<int, int> res;

        res.reserve(source.size());

        for (auto &f : fnd)
        {
            auto it = find(source.begin(), source.end(), source[f]);
            if (it != source.end())
            {
                res[*it]++;
            }
        }

        return res;
    }

    void intersect(unordered_map<int, int> &cnt1, unordered_map<int, int> &cnt2, vector<int> &res)
    {
        for (auto &c : cnt1)
        {
            auto it = cnt2.find(c.first);
            if (it != cnt2.end())
            {
                res.push_back(min(c.second, it->second));
            }
        }
    }

    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        vector<vector<int>> adj(source.size());
        int res = source.size();

        for (auto &a : allowedSwaps)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }

        vector<int> visited(source.size(), 0);

        for (int i = 0; i < source.size(); i++)
        {
            if (visited[i] == 0)
            {
                vector<int> found;
                vector<int> cnt;

                found.reserve(source.size());

                dfs(adj, i, visited, found);

                unordered_map<int, int> cnt1(check(source, found));
                unordered_map<int, int> cnt2(check(target, found));

                intersect(cnt1, cnt2, cnt);

                res -= accumulate(cnt.begin(), cnt.end(), 0);
            }
        }

        return res;
    }
};

class UnionFind
{
public:
    UnionFind(int n)
        : rank(n, 1), f(n, 0)
    {
        for (int i = 0; i < n; ++i)
        {
            f[i] = i;
        }
    }

    int Find(int x)
    {
        if (x == f[x])
            return x;
        else
            return Find(f[x]);
    }

    void Union(int x, int y)
    {
        int fx = Find(x);
        int fy = Find(y);

        if (fx == fy)
            return;

        if (rank[fx] > rank[fy])
            swap(fx, fy);

        f[fx] = fy;

        if (rank[fx] == rank[fy])
            rank[fy]++;
    }

private:
    vector<int> f, rank;
};

class SolutionAdvanced
{
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        const int n = source.size();

        UnionFind uf(n);

        for (const auto &v : allowedSwaps)
        {
            uf.Union(v[0], v[1]);
        }

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; ++i)
        {
            groups[uf.Find(i)].push_back(i);
        }

        int match = 0;
        for (const auto &[_, group] : groups)
        {
            unordered_map<int, int> ts;

            for (const int i : group)
                ++ts[target[i]];

            for (const int i : group)
            {
                int &cnt = ts[source[i]];

                if (cnt > 0)
                {
                    ++match;
                    --cnt;
                }
            }
        }

        return n - match;
    }
};

int main()
{
}