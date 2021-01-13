#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int left, int right)
{
    int piv = arr[right];
    int l = left;

    for (int i = left; i < right; i++)
    {
        if (arr[i] <= piv)
        {
            std::swap(arr[i], arr[l++]);
        }
    }

    std::swap(arr[l], arr[right]);

    return l;
}

void quick(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);

        quick(arr, left, p - 1);
        quick(arr, p + 1, right);
    }
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 5, 7};

    quick(arr, 0, arr.size() - 1);

    for (const auto &a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}