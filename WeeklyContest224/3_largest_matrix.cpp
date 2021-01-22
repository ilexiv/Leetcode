#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &a)
    {
        vector<int> count(a[0].size(), 0);
        int result = 0;

        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < a[0].size(); ++j)
            {
                count[j] = (a[i][j] ? count[j] + 1 : 0);
            }

            vector<int> b = count;
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());

            for (int j = 0; j < count.size(); ++j)
            {
                result = max(result, (j + 1) * b[j]);
            }
        }
        return result;
    }
};

int main()
{
}