#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int> &arr, int l, int r)
{
    int piv = arr[r];
    int le = l;

    for (int i = l; i < r; i++)
    {
        if (arr[i] < piv)
        {
            std::swap(arr[i], arr[le++]);
        }
    }

    std::swap(arr[le], arr[r]);

    return le;
}

int largest_number(std::vector<int> &num, int k)
{
    int size = num.size();
    int l = 0;
    int r = size - 1;

    while (l <= r)
    {
        int piv = partition(num, l, r);

        if (piv == size - k)
        {
            return num[piv];
        }
        else if (piv > size - k)
        {
            r = piv - 1;
        }
        else
        {
            l = piv + 1;
        }
    }

    return -1;
}

int lowest_number(std::vector<int> &num, int k)
{
    int size = num.size();
    int l = 0;
    int r = size - 1;

    while (l <= r)
    {
        int piv = partition(num, l, r);

        if (piv == k - 1)
        {
            return num[piv];
        }
        else if (piv > k - 1)
        {
            r = piv - 1;
        }
        else
        {
            l = piv + 1;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> arr = {1, 3, 3,3,3, 2, 0, 9, 4, 8, 6, 6, 6, 6, 6, 6, 5};

    std::cout << largest_number(arr, 1) << std::endl;
    std::cout << largest_number(arr, 2) << std::endl;
    std::cout << largest_number(arr, 3) << std::endl;
    std::cout << largest_number(arr, 4) << std::endl;
    std::cout << largest_number(arr, 5) << std::endl;

    std::cout << lowest_number(arr, 1) << std::endl;
    std::cout << lowest_number(arr, 2) << std::endl;
    std::cout << lowest_number(arr, 3) << std::endl;
    std::cout << lowest_number(arr, 4) << std::endl;
    std::cout << lowest_number(arr, 5) << std::endl;

    return 0;
}