#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/decode-xored-array/

XOR truth table
Input	Output
A	B
0	0	0
0	1	1
1	0	1
1	1	0

A[i] = res[i] ^ res[i + 1] // Original
A[i] ^ A[i] ^ res[i+1] = res[i] ^ res[i+1] ^ A[i] ^ res[i+1] // Let's add A[i] ^ res[i+1]
res[i+1] = res[i] ^ A[i]
#endif

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> res = {first};

        for (auto el : encoded)
        {
            res.push_back(first ^= el);
        }

        return res;
    }
};

int main()
{
}