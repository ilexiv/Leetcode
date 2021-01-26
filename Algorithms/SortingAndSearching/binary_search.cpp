#include <iostream>
#include <vector>
#include <algorithm>

int binary_search(std::vector<int> &arr, int el)
{
    int l = 0;
    int r = arr.size();

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == el)
        {
            return mid;
        }

        if (arr[mid] < el)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 5, 7};

    std::sort(arr.begin(), arr.end());

    std::cout << binary_search(arr, 5) << std::endl;

    return 0;
}