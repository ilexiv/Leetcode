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
https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
#endif

class Solution {
public:
    bool helper(string s, long long int tar) {
        if (stoull(s) == tar) return true;
        for (int i = 1; i < s.size(); ++i) {
            if (stoull(s.substr(0, i)) != tar) continue;
            if (helper(s.substr(i), tar - 1)) return true;
        }
        return false;
    }
    
public:
    bool splitString(string s) {
        for (int i = 1; i < s.size(); ++i) {
            long long int tar = stoull(s.substr(0, i));
            if (helper(s.substr(i), tar - 1)) return true;
        }
        return false;
    }
};

int main()
{
}