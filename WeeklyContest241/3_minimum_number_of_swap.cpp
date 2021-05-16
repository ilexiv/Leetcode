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
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
#endif

class Solution {
public:
    int helper(string& s, char start) {
        int swaps = 0;
        char prev = start;
        for (int i = 0; i < s.size(); i++) {
            swaps += s[i] != prev;
            prev = prev == '1' ? '0' : '1';
        }
        return swaps / 2;
    }
    int minSwaps(string s) {
        int ones = 0, zeros = 0;
        for (auto& c : s) {
            ones += c == '1';
            zeros += c == '0';
        }
        if (abs(ones - zeros) > 1) return -1;
        if (ones > zeros) return helper(s, '1');
        if (ones < zeros) return helper(s, '0');
        return min(helper(s, '1'), helper(s, '0'));
    }
};

int main()
{
}