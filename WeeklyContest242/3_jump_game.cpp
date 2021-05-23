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
https://leetcode.com/problems/jump-game-vii/
#endif

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int fastest = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (node >= s.size() - 1) return true;
            int start = max(fastest + 1, node + minJump);
            int end = min(node + maxJump + 1, (int)s.size());
            for (int i = start; i < end; i++) {
                if (s[i] == '0') q.push(i); 
            }
            fastest = node + maxJump;
        }
        return false;
    }
};


int main()
{
}