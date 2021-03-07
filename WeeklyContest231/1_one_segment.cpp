#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
#endif

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '1' && s[i - 1] == '0')
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
}