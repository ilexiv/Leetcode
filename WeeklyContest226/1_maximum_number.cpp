#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/contest/weekly-contest-226/problems/maximum-number-of-balls-in-a-box/
#endif

class Solution
{
public:
    int count(int n)
    {
        int cnt = 0;
        while (n > 0)
        {
            cnt += n % 10;
            n /= 10;
        }
        return cnt;
    }
    int countBalls(int lowLimit, int highLimit)
    {
        unordered_map<int, int> hmap;

        for (int i = lowLimit; i <= highLimit; i++)
        {
            hmap[count(i)]++;
        }

        int res = 0;
        for (auto &el : hmap)
        {
            res = max(res, el.second);
        }
        return res;
    }
};

int main()
{
}