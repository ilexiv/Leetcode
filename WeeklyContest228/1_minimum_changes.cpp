#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
#endif

// modulo operation on index sequence [1,2,3,4,5,.....] with 2
// wiil give an array of [0,1,0,1,0,1......]. The other sequence 
// can start with 1,0,1,.. But we don't need to calculate the
// result again, as we can substitute s.size() - res;
class Solution
{
public:
    int minOperations(string s)
    {
        int res = 0;
        int size = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - '0' != i % 2)
            {
                res++;
            }
        }
        return std::min(res, size - res);
    }
};

int main()
{
}