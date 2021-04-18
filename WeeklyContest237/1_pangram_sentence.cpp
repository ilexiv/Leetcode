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
https://leetcode.com/problems/check-if-the-sentence-is-pangram/
#endif

class Solution {
public:
    bool checkIfPangram(string sentence) {
#if 0
        unordered_set<char> sent(sentence.begin(), sentence.end());
        return sent.size() == 26;
#endif
        vector<bool> chars(26, false);
        for (auto c : sentence) chars[c - 'a'] = true;
        for (auto b : chars) {
            if (b == false) return false;
        }
        return true;
    }
};

int main()
{
}