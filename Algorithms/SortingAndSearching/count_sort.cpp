#include <iostream>
#include <vector>
#include <algorithm>

void count_sort(std::vector<int> &arr)
{
    auto maxel = std::max_element(arr.begin(), arr.end());
    std::vector<int> freq(*maxel + 1, 0);
    std::vector<int> res(*maxel + 1, 0);

    // count frequency
    for (auto &el : arr)
    {
        ++freq[el];
    }

    // calculate starting position
    for (int i = 1; i <= *maxel; i++)
    {
        freq[i] += freq[i - 1];
    }

    for (int i = 0; i < arr.size(); i++)
    {
        res[freq[arr[i]] - 1] = arr[i];
        --freq[arr[i]];
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = res[i];
    }
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 5, 7};

    count_sort(arr);

    for (const auto &a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}