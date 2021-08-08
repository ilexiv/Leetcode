
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
#include <set>

using namespace std;

#if 0
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
#endif

class Solution {
public:
    int minSwaps(string s) {
        int res = 0, open = 0, close = 0;
        for (int i = 0, j = s.size() - 1; i < j; i++) {
            if (s[i] == '[') open++;
            if (s[i] == ']') close++;
            if (close > open) {
                while (s[j] != '[') j--;
                swap(s[i], s[j]);
                res++, close--, open++;
            }
        }
        return res;
    }
};

int main()
{
}