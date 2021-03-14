#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
#endif

class Solution2
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> dif;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                dif.push_back(i);
            }
        }

        return dif.empty() ||
               (dif.size() == 2 &&
                (s1[dif[0]] == s2[dif[1]] || s2[dif[0]] == s1[dif[1]]));
    }
};

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = i + 1; j < s1.size(); j++)
            {
                swap(s1[i], s1[j]);
                if (s1 == s2)
                    return true;
                swap(s1[i], s1[j]);
            }
        }
        return false;
    }
};

int main()
{
}