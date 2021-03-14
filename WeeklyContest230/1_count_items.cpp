#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/count-items-matching-a-rule/
#endif

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int count = 0;

        for (auto &i : items)
        {
            if (ruleKey == "type" && ruleValue == i[0] ||
                ruleKey == "color" && ruleValue == i[1] ||
                ruleKey == "name" && ruleValue == i[2])
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
}