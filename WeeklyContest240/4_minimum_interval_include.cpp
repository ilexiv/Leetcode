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
#include <array>
#include <set>

using namespace std;

#if 0
https://leetcode.com/problems/minimum-interval-to-include-each-query/
#endif

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& inter, vector<int>& queries) {
        using ip = pair<int, int>;
        vector<int> sq = queries;
        sort(sq.begin(), sq.end());
        sort(inter.begin(), inter.end());
        priority_queue<ip, vector<ip>, greater<ip>> pq;
        vector<int> res;
        unordered_map<int, int> hmap;
        int i = 0, sz = inter.size();
        for (auto& q : sq) {
            while (i < sz && inter[i][0] <= q) {
                int l = inter[i][0];
                int r = inter[i][1];
                pq.push({r - l + 1, r});
                i++;
            }
            while (!pq.empty() && pq.top().second < q) pq.pop();
            hmap[q] = pq.empty() ? -1 : pq.top().first;
        }
        for (auto& q : queries) res.push_back(hmap[q]);
        return res;
    }
};

int main()
{
}