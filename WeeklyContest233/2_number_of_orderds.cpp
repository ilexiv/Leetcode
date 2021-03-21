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
https://leetcode.com/problems/number-of-orders-in-the-backlog/
#endif

class Solution
{
public:
    int getNumberOfBacklogOrders(vector<vector<int> > &orders)
    {
        using ip = pair<int, int>;
        priority_queue<ip> maxh;
        priority_queue<ip, vector<ip>, greater<ip> > minh;
        long long backlog = 0;

        for (auto &o : orders)
        {
            if (o[2] == 0)
            { // buy
                while (!minh.empty() && minh.top().first <= o[0])
                {
                    auto [price, freq] = minh.top();
                    int minel = min(freq, o[1]);
                    if (!minel)
                        break;
                    o[1] -= minel;
                    freq -= minel;
                    backlog -= minel;
                    minh.pop();
                    if (freq > 0)
                    {
                        minh.push({price, freq});
                    }
                }
                if (o[1])
                {
                    maxh.push({o[0], o[1]});
                    backlog += o[1];
                }
            }
            else
            { // sell
                while (!maxh.empty() && maxh.top().first >= o[0])
                {
                    auto [price, freq] = maxh.top();
                    int minel = min(freq, o[1]);
                    if (!minel)
                        break;
                    o[1] -= minel;
                    freq -= minel;
                    backlog -= minel;
                    maxh.pop();
                    if (freq > 0)
                    {
                        maxh.push({price, freq});
                    }
                }
                if (o[1])
                {
                    minh.push({o[0], o[1]});
                    backlog += o[1];
                }
            }
        }

        const long int modul = 1e9 + 7;
        return backlog % modul;
    }
};

int main()
{
}