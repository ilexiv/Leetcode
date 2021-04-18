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
https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
#endif

#if 0
arr1 = [1,2], arr2 = [8,9] 

(1 AND 8) XOR (1 AND 9) XOR (2 AND 8) XOR (2 AND 9)

We can simplify both parts:
(1 AND 8) XOR (1 AND 9) = 1 AND (8 XOR 9)
(2 AND 8) XOR (2 AND 9) = 2 AND (8 XOR 9)

Then:
(1 AND 8) XOR (1 AND 9) XOR (2 AND 8) XOR (2 AND 9) = (1 AND (8 XOR 9)) XOR (2 AND (8 XOR 9))

And then we can simplify more:
(1 AND (8 XOR 9)) XOR (2 AND (8 XOR 9)) = (8 XOR 9) AND (1 XOR 2)
#endif

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int andarr = 0, xorarr = 0;
        for (auto a : arr1) andarr ^= a;
        for (auto a : arr2) xorarr ^= a;
        return andarr & xorarr;
    }
};

int main()
{
}