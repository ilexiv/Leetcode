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
https://leetcode.com/problems/sign-of-the-product-of-an-array/
#endif

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) res *= -1;
            if (nums[i] == 0) return 0;
        }
        return res;
    }
};

int main()
{
}