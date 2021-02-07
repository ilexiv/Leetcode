#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

#if 0
https://leetcode.com/contest/weekly-contest-226/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
#endif

class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        vector<long> sum;
        long s = 0;
        for (int x : candiesCount)
        {
            sum.push_back(s += x);
        }

        vector<bool> answer;

        for (auto &p : queries)
        {
            LL L = (sum[p[0]] - candiesCount[p[0]]) / p[2];
            LL R = sum[p[0]] - 1;

            answer.push_back(L <= p[1] && R >= p[1]);
        }

        return answer;
    }
};

int main()
{
}