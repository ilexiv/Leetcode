#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#if 0
https://leetcode.com/problems/truncate-sentence/
#endif

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' && --k == 0)
                return s.substr(0, i);
        }
        return s;
    }
};

int main()
{
}