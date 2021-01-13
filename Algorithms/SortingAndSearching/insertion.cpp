#include <iostream>
#include <vector>

void insertion(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 5, 7};

    insertion(arr);

    for (const auto &a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}