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
https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
#endif

class Solution1 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res(nums.size(), 0);
        int ind = 0;
        for (int i = 0; i < nums.size(); i += 2) res[i] = nums[ind++];
        for (int i = 1; i < nums.size(); i += 2) res[i] = nums[ind++];
        return res;
    }
};

class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        deque<int> dq;
        for (auto n : nums) dq.push_back(n);
        while (!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
            if (!dq.empty()) {
                res.push_back(dq.back()); dq.pop_back();
            }
        }
        return res;
    }
};

int main()
{
}