#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string maximumTime(string time)
    {
        std::string res = time;

        if (time[0] == '?' && time[1] == '?')
        {
            res[0] = '2';
            res[1] = '3';
        }
        else if (time[0] == '?')
        {
            if (time[1] < '4')
                res[0] = '2';
            else
                res[0] = '1';
        }
        else if (time[1] == '?')
        {
            if (time[0] == '2')
                res[1] = '3';
            else
                res[1] = '9';
        }

        if (time[3] == '?')
            res[3] = '5';
        if (time[4] == '?')
            res[4] = '9';

        return res;
    }
};

int main()
{
}