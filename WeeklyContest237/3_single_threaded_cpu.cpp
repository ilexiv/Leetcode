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
https://leetcode.com/problems/single-threaded-cpu/
#endif

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res, index(tasks.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int lhs, int rhs) {
           return  tasks[lhs][0] < tasks[rhs][0];
        });
        using ip = pair<int, int>;
        priority_queue<ip, vector<ip>, greater<ip>> pq;
        for (long i = 0, time = 1; i < index.size() || !pq.empty();) {
            while (i < index.size() && tasks[index[i]][0] <= time) {
                pq.push({tasks[index[i]][1], index[i]});
                i++;
            }
            if (!pq.empty()) {
                auto [proc, ind] = pq.top(); pq.pop();
                res.push_back(ind);
                time += proc;
            } else {
                time = tasks[index[i]][0];
            }
        }
        return res;
    }
};

int main()
{
}