
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
    long long minimumPerimeter(long long neededApples) {
        long long i = 1;
        for (; neededApples > 0; i++) {
            neededApples -= 12 * i;
            neededApples -= (((2 * i) * (2 * i - 1)) / 2 - (i * (i + 1)) / 2) * 8;
        }
        return (i - 1) * 8;
    }
};

int main()
{
}