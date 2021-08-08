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
https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
#endif

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp;
        for (auto& w : words) {
            temp += w;
            if (temp == s) return true;
        }
        return false;
    }
};

int main()
{
}