#include <iostream>
#include <vector>
#include <algorithm>

int lower_bound(std::vector<int> &arr, int el)
{
    int l = 0;
    int r = arr.size();

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] < el)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    return l;
}

int upper_bound(std::vector<int> &arr, int el)
{
    int l = 0;
    int r = arr.size();

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] <= el)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    return l;
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 6, 6, 6, 6, 6, 6, 5};

    std::sort(arr.begin(), arr.end());

    for (auto &a : arr)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::cout << lower_bound(arr, 6) << std::endl;
    std::cout << upper_bound(arr, 6) << std::endl;

    std::cout << lower_bound(arr, 7) << std::endl;
    std::cout << upper_bound(arr, 7) << std::endl;

    return 0;
}