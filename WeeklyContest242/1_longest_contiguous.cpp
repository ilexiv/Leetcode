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
https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
#endif

class Solution {
public:
    int countme(string& s, char c) {
        int res = 0, temp = 0;;
        for (int i = 0; i < s.size(); i++) {
            temp = s[i] == c ? temp + 1 : 0;
            res = max(temp, res);
        }
        return res;
    }
    bool checkZeroOnes(string s) {
        return countme(s, '1') > countme(s, '0');
    }
};

class Solution1 {
public:
    bool checkZeroOnes(string s) {
        int maxone = 0, maxzero = 0, one = 0, zero = 0;
        for (auto& c : s) {
            if (c == '1') {
                one++;
                maxone = max(maxone, one);
                zero = 0;
            } else {
                zero++;
                maxzero = max(maxzero, zero);
                one = 0;
            }
        }
        return maxone > maxzero;
    }
};

int main()
{
}