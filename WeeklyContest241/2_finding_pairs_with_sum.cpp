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
https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
#endif

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    : n1(nums1)
    , n2(nums2) {
        for (auto& n : nums2) hmap2[n]++;
    }
    
    void add(int index, int val) {
        hmap2[n2[index]]--;
        n2[index] += val;
        hmap2[n2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int i = 0; i < n1.size(); i++) {
            if (hmap2.count(tot - n1[i]))
                cnt += hmap2[tot - n1[i]];
        }
        return cnt;
    }
private:
    vector<int> &n1;
    vector<int> &n2;
    unordered_map<int, int> hmap2;
};

int main()
{
}