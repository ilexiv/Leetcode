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
https://leetcode.com/problems/minimum-sideway-jumps/
#endif

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        using ip = pair<int, pair<int, int>>;
        int size = obstacles.size();
        queue<ip> q;
        vector<vector<bool>> vis(4, vector<bool>(size, false));
        int sidej = INT_MAX;
        q.push({0, {2, 0}});
        vis[2][0] = true;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int point = p.second.second;
            int line = p.second.first;
            int jumps = p.first;
            if (point >= size) return jumps;
            if (obstacles[point + 1] != line) {
                q.push({jumps, {line, point + 1}});
                vis[line][point + 1] = true;
            } else {
                for (int i = 1; i <= 3; i++) {
                    if (i != line && obstacles[point] != i) {
                        if (!vis[i][point]) {
                            q.push({jumps + 1, {i, point}});
                            vis[i][point] = true;
                        }
                    }
                }   
            }
        }
        return sidej;
    }
};

int main()
{
}