#include <iostream>
#include <vector>

int get_num()
{
    std::cout << "get_num" << std::endl << std::flush;
    int ret;
    std::cin >> ret;
    return ret;
}

int guess(int index, int x)
{
    std::cout << "guess " << index << " " << x << std::endl << std::flush;
    int ret;
    std::cin >> ret;
    return ret;
}

void submit(const std::vector<int> &result)
{
    std::cout << "submit ";
    for (std::vector<int>::const_iterator iter = result.begin(); iter != result.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl << std::flush;
}
