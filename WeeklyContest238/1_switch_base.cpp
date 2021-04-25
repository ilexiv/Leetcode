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
https://leetcode.com/problems/sum-of-digits-in-base-k/
#endif

class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n > 0) {
            res *= 10;
            res += n % k;
            n /= k;
        }
        int sum = 0;
        while (res > 0) {
            sum += res % 10;
            res /= 10;
        }
        return sum;
    }
};

class Solution1 {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n > 0) {
            res += n % k;
            n /= k;
        }
        return res;
    }
};

int main()
{
}