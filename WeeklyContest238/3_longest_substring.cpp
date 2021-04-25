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
https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
#endif

class Solution {
public:
    string compress_string(string& word, vector<int>& freq) {
        string compressed;
        compressed += word[0];
        int j = 0;
        for (int i = 0; i < word.size(); i++) {
            while (i < word.size() && word[i] == compressed.back()) i++;
            if (i < word.size()) {
                freq.push_back(freq.empty() ? i - j : freq.back() + i - j);
                compressed += word[i];
                j = i;
            }
        }
        if (!freq.empty())
            freq.push_back(freq.back() + word.size() - j);
        return compressed;
    }
    int longestBeautifulSubstring(string word) {
        vector<int> freq;
        string compressed = compress_string(word, freq);
        if (compressed.size() < 5) return 0;
        int res = 0;
        for (int i = 0; i < compressed.size() - 4; i++) {
            if (compressed.substr(i, 5) == "aeiou") {
                int sum = i == 0 ? freq[i + 4] : freq[i + 4] - freq[i - 1] ;
                res = max(res, sum);
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int longestBeautifulSubstring(string word) {
        int res = 0;
        for (int i = 0; i < word.size() - 1; i++) {
            if (word[i] == 'a') {
                int clen = 1, uchars = 1;
                while (i < word.size() && word[i] <= word[i + 1]) {
                    uchars += word[i] < word[i + 1] ? 1 : 0;
                    clen++;
                    i++;
                }
                if (uchars == 5) res = max(res, clen);
            }
        }
        return res;
    }
};

int main()
{
}