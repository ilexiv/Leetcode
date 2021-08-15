
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
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
#endif

class Solution {
public:
    const long long MOD = 1e9 + 7l;
    int minNonZeroProduct(int p) {
        long long pr = (1l << p) - 1l;
        long long prm = pr - 1l;
        long long prd = pr / 2l;
        long long mul = expn(prm, prd);
        return (mul % MOD) * (pr % MOD) % MOD;
    }
    long long expn(long long n, long long k){
        if (k == 0) return 1;
        if (k == 1) return n % MOD;
        if (k % 2 == 0){
            long long temp = expn(n, k / 2);
            return (temp * temp) % MOD;
        } else {
            long long temp = expn(n, k / 2);
            temp = (temp * temp) % MOD;
            return (temp * (n % MOD)) % MOD;
        }
    }
};

int main()
{
}