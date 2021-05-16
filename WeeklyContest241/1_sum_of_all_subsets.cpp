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
https://leetcode.com/problems/sum-of-all-subset-xor-totals/
#endif

#if 0
[a,b,c]
000    -> Empty set
001    -> a
010    -> b
011    -> ab
100    -> c
101    -> ac
110    -> bc
111    -> abc
#endif
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sets = 1 << nums.size();
        int res = 0;
        for (int i = 1; i < sets; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) sum ^= nums[j];
            }
            res += sum;
        }
        return res;
    }
};

int main()
{
}