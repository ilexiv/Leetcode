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

class Solution
{
public:
    int minCharacters(string a, string b)
    {
        unordered_map<char, int> fa;
        unordered_map<char, int> fb;

        for (auto c : a)
            fa[c]++;
        for (auto c : b)
            fb[c]++;

        int sizea = a.size();
        int sizeb = b.size();
        int ressize = sizea + sizeb;

        for (char i = 'a'; i <= 'z'; i++)
        {
            ressize = min(ressize, sizea + sizeb - fa[i] - fb[i]);

            if (i > 'a')
            {
                fa[i] += fa[i - 1];
                fb[i] += fb[i - 1];
            }

            if (i < 'z')
            {
                ressize = min(ressize, sizea - fa[i] + fb[i]);
                ressize = min(ressize, sizeb - fb[i] + fa[i]);
            }
        }

        return ressize;
    }
};

int main()
{
}