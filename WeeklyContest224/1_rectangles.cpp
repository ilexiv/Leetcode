#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int res = 0;
        int maxel = INT_MIN;

        for (auto &r : rectangles)
        {
            int m = min(r[0], r[1]);

            if (m > maxel)
            {
                res = 1;
                maxel = m;
            }
            else if (m == maxel)
            {
                res++;
            }
        }

        return res;
    }
};

int main()
{
}