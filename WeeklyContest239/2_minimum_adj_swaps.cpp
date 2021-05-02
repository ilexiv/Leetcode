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
https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
#endif

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string temp = num;
        while (k-- > 0) next_permutation(temp.begin(), temp.end());
        int res = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != temp[i]) {
                int j = i;
                while (num[i] != temp[j]) j++;
                res += j - i;
                while (j > i) {
                    swap(temp[j], temp[j - 1]);
                    j--;
                }
            }
        }
        return res;
    }
};

int main()
{
}