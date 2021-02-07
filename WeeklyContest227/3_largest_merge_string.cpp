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
https://leetcode.com/problems/largest-merge-of-two-strings/
#endif

class Solution
{
public:
    string largestMerge(string word1, string word2)
    {
        string res;

        int l1 = 0;
        int r1 = word1.size();

        int l2 = 0;
        int r2 = word2.size();

        while (l1 < r1 && l2 < r2)
        {
            if (word1[l1] > word2[l2])
            {
                res += word1[l1++];
            }
            else if (word2[l2] > word1[l1])
            {
                res += word2[l2++];
            }
            else
            {
                if (word1.substr(l1) > word2.substr(l2))
                {
                    res += word1[l1++];
                }
                else
                {
                    res += word2[l2++];
                }
            }
        }

        while (l1 < r1)
        {
            res += word1[l1++];
        }

        while (l2 < r2)
        {
            res += word2[l2++];
        }

        return res;
    }
};

int main()
{
}