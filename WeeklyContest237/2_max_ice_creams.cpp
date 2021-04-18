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
https://leetcode.com/problems/maximum-ice-cream-bars/
#endif

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
#if 0
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& c : costs) pq.push(c);
        int res = 0;
        while (!pq.empty() && coins > 0 ) {
            int cost = pq.top(); pq.pop();
            coins -= cost;
            res += coins >= 0;
        }
        return res;
#endif
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            coins -= costs[i];
            if (coins < 0) return i;
        }
        return costs.size();
    }
};

int main()
{
}