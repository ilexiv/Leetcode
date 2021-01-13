#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    std::vector<int> temp(right - left + 1, 0);
    int l = left;
    int r = mid + 1;
    int cnt = 0;

    while (l <= mid && r <= right)
    {
        if (arr[l] < arr[r])
        {
            temp[cnt++] = arr[l++];
        }
        else
        {
            temp[cnt++] = arr[r++];
        }
    }

    while (l <= mid)
    {
        temp[cnt++] = arr[l++];
    }

    while (r <= right)
    {
        temp[cnt++] = arr[r++];
    }

    for (int i = left, cnt = 0; i <= right; i++)
    {
        arr[i] = temp[cnt++];
    }
}

void merge_sort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 5, 7};

    merge_sort(arr, 0, arr.size() - 1);

    for (const auto &a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}