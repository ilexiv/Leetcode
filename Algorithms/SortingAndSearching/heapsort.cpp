#include <iostream>
#include <vector>

void heapify(std::vector<int> &arr, int root, int size)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest = root;

    if (left < size && arr[left] > arr[root])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != root)
    {
        std::swap(arr[largest], arr[root]);
        heapify(arr, largest, size);
    }
}

void heap_sort(std::vector<int> &arr)
{
    for (int i = arr.size() / 2; i >= 0; i--)
    {
        heapify(arr, i, arr.size());
    }

    for (int i = arr.size() - 1; i > 0; i--)
    {
        std::swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 5, 7};

    heap_sort(arr);

    for (const auto &a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}