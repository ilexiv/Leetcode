#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <unordered_set>

using namespace std;

#if 0
https://leetcode.com/problems/count-number-of-homogenous-substrings/
#endif


// For "a" : 1
// For "aa": 3 (1 + 2)
// For "aaa": 6 (1 + 2 + 3)
// So, we incease cnt if the previous character is the same (and reset it to 1 otherwise).
class Solution {
public:
    int countHomogenous(string s) {
        int res = 0;
        int count = 0;
        char prev = s[0];
        
        for (auto& c : s) {
            count = c == prev ? count + 1 : 1;
            res = (res + count) % (1000000007);
            prev = c;
        }
        return res;
    }
};

int main()
{
}