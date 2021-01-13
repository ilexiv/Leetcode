#include <iostream>
#include <vector>

void bubble(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> arr = {1, 3, 2, 0, 9, 4, 8, 5, 7};

    bubble(arr);

    for (const auto &a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}