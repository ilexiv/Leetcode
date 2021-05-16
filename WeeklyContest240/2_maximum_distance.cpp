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
https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
#endif

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int dist = 0;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                i++;
            } else {
                dist = max(dist, j - i);
                j++;
            }
        }
        return dist;

        #if 0
        int dist = 0;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (i <= j && nums1[i] <= nums2[j]) {
                dist = max(dist, j - i);
                j++;
            } else {
                if (nums1[i] > nums2[j])
                    i++;
                else
                    j++;
            }
        }
        return dist;
        #endif
    }
};

int main()
{
}