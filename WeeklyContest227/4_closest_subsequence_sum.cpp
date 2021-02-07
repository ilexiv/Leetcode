#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

#if 0
https://leetcode.com/problems/closest-subsequence-sum/
#endif

class Solution {
public:
    void dfs(int start, int end,  int sum, vector<int>& hset, vector<int>& nums) {
        if (start >= end) {
            hset.push_back(sum);
            return;
        }
        dfs(start + 1, end, sum + nums[start], hset, nums); 
        dfs(start + 1, end, sum, hset, nums);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> hset1, hset2;
        
        dfs(0, nums.size() / 2, 0, hset1, nums);
        dfs(nums.size() / 2, nums.size(), 0, hset2, nums);
        
        sort(hset2.begin(), hset2.end());
        
        int res = INT_MAX;
        for (int i = 0; i < hset1.size(); i++) {
            auto it = upper_bound(hset2.begin(), hset2.end(), goal - hset1[i]);
            
            if (it != hset2.end()) {
                res = min(res, abs(goal - hset1[i] - *it));
            }
            
            if (it != hset2.begin()) {
                res = min(res, abs(goal -  hset1[i] - *(--it)));
            }
        }
        
        return res;
    }
};

int main()
{
}