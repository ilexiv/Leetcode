#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <numeric>
#include <queue>

using namespace std;

#if 0
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
#endif

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](auto& s1, auto& s2){
             if (s1.size() != s2.size()) return s1.size() < s2.size();
             else return s1 < s2;
        });
        return nums[nums.size() - k];
    }
};

int main()
{
}