
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
https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
#endif

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> dp, ret;
        for(auto x : obstacles) {
            auto it = upper_bound(dp.begin(), dp.end(), x); 
            if (it != dp.end()) cout << *it << endl;
            ret.push_back(it - dp.begin() + 1);
            if (it == dp.end()) dp.push_back(x);
            else *it = x;
        }
        return ret;
    }
};

int main()
{
}