#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <array>

using namespace std;

#if 0
https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
#endif

class Solution
{
public:
    string evaluate(string s, vector<vector<string> > &knowledge)
    {
        unordered_map<string, string> hmap;
        for (auto &k : knowledge)
            hmap[k[0]] = k[1];
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '(')
            {
                res += s[i];
            }
            else
            {
                string val;
                while (s[++i] != ')')
                    val += s[i];
                res += hmap.count(val) ? hmap[val] : "?";
            }
        }
        return res;
    }
};

int main()
{
}