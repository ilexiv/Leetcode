#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        vector<vector<int>> matrix2 = matrix;
        vector<int> vec;

        vec.push_back(matrix[0][0]);

        for (int i = 1; i < matrix[0].size(); i++)
        {
            matrix2[0][i] = matrix[0][i] ^ matrix2[0][i - 1];
            vec.push_back(matrix2[0][i]);
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            matrix2[i][0] = matrix[i][0] ^ matrix2[i - 1][0];
            vec.push_back(matrix2[i][0]);
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                matrix2[i][j] = matrix[i][j] ^ matrix2[i - 1][j] ^ matrix2[i][j - 1] ^ matrix2[i - 1][j - 1];
                vec.push_back(matrix2[i][j]);
            }
        }

        sort(vec.begin(), vec.end());

        return vec[vec.size() - k];
    }
};

class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        vector<vector<int>> m2 = matrix;
        vector<int> vec;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    m2[i][j] = matrix[i][j];
                }
                else if (i == 0)
                {
                    m2[i][j] = matrix[i][j] ^ m2[i][j - 1];
                }
                else if (j == 0)
                {
                    m2[i][j] = matrix[i][j] ^ m2[i - 1][j];
                }
                else
                {
                    m2[i][j] = matrix[i][j] ^ m2[i][j - 1] ^ m2[i - 1][j] ^ m2[i - 1][j - 1];
                }
                vec.push_back(m2[i][j]);
            }
        }

        sort(vec.begin(), vec.end());

        return vec[vec.size() - k];
    }
};

int main()
{
}