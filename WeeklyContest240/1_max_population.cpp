#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#if 0
https://leetcode.com/problems/maximum-population-year/
#endif

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(200, 0);
        for (auto& l : logs) {
            years[l[0] - 1950]++;
            years[l[1] - 1950]--;
        }
        int cnt = 0, res = 0;
        int year = -1;
        for (int i = 0; i < years.size(); i++) {
            cnt += years[i];
            if (cnt > res) {
                res = cnt;
                year = i + 1950;
            }
        }
        return year;
    }
};

class Solution2 {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(200, 0);
        for (auto& l : logs) {
            years[l[0] - 1950]++;
            years[l[1] - 1950]--;
        }
        int year = 1950;
        for (int i = 1; i < years.size(); i++) {
            years[i] += years[i - 1];
            if (years[i] > years[year - 1950]) {
                year = i + 1950;
            }
        }
        return year;
    }
};

int main()
{
}