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
https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
#endif

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (auto& p : patterns) {
            if (word.find(p) != string::npos) res++;
        }
        return res;
    }
};

int main()
{
}