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
https://leetcode.com/problems/find-the-winner-of-the-circular-game/
#endif

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> c(n, 0);
        iota(c.begin(), c.end(), 1);
        int ind = 0;
        while (c.size() > 1) {
            ind = (ind + k - 1) % c.size();
            c.erase(c.begin() + ind);
        }
        return c[0];
    }
};

class Solution2 {
public:
    int findTheWinner(int n, int k) {
        int ind = 0;
        for (int i = 1; i <= n; i++) {
            ind = (ind + k) % i;
        }
        return ind + 1;
    }
};

int main()
{
}