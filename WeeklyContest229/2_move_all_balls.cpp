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

using namespace std;

#if 0
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
#endif

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> res;

        for (int i = 0; i < boxes.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < boxes.size(); j++)
            {
                if (i != j)
                {
                    if (boxes[j] == '1')
                        count += abs(i - j);
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

class Solution1
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> res(boxes.size(), 0);

        for (int i = 0, cnt = 0, ops = 0; i < boxes.size(); i++)
        {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }

        for (int i = boxes.size() - 1, cnt = 0, ops = 0; i >= 0; i--)
        {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }

        return res;
    }
};

int main()
{
}