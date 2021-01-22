#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> hmap;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int mul = nums[i] * nums[j];
                res += hmap[mul];
                hmap[mul]++;
            }
        }

        return res * 8;
    }
};

int main()
{
}