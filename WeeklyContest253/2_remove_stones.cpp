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
https://leetcode.com/problems/remove-stones-to-minimize-the-total/
#endif

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int res = accumulate(piles.begin(), piles.end(), 0);
        while (k-- > 0) {
            int p = pq.top(); pq.pop();
            res -= floor(p / 2);
            pq.push(p - p / 2);
        }
        return res;
    }
};

int main()
{
}